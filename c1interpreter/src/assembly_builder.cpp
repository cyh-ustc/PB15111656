
#include "assembly_builder.h"

#include <vector>
#include <array>


using namespace llvm;
using namespace c1_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node)
{
    bb_count = 0;
    for(auto i : node.global_defs)
        i->accept(*this);
    return;
}

void assembly_builder::visit(func_def_syntax &node)
{
    in_global = false;
    auto got = functions.find(node.name);
    if(got == functions.end())
    {
        current_function = Function::Create(FunctionType::get(Type::getVoidTy(context), {}, false),  GlobalValue::LinkageTypes::ExternalLinkage, node.name, module.get());
        auto bb = BasicBlock::Create(context, "entry", current_function);
        builder.SetInsertPoint(bb);
        functions.emplace(node.name, current_function);
        node.body->accept(*this);
        builder.CreateRetVoid();
        builder.ClearInsertionPoint();
    }
    else
    {
        err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
        error_flag = true;
    }
    in_global = true;
    return;
}

void assembly_builder::visit(cond_syntax &node)
{
    node.lhs->accept(*this);
    auto l = value_result;
    node.rhs->accept(*this);
    auto r = value_result;
    switch(node.op)
    {
        case relop::equal:
            value_result = builder.CreateICmpEQ(l, r);
            break;
        case relop::non_equal:
            value_result = builder.CreateICmpNE(l, r);
            break;
        case relop::less:
            value_result = builder.CreateICmpSLT(l, r);
            break;
        case relop::less_equal:
            value_result = builder.CreateICmpSLE(l, r);
            break;
        case relop::greater:
            value_result = builder.CreateICmpSGE(l, r);
            break;
        case relop::greater_equal:
            value_result = builder.CreateICmpEQ(l, r);
            break;
    }
    return;
}

void assembly_builder::visit(binop_expr_syntax &node)
{
    if(constexpr_expected)
    {
        node.lhs->accept(*this);
        auto l = const_result;
        node.rhs->accept(*this);
        auto r = const_result;
        switch(node.op)
        {
            case binop::plus:
                const_result = l + r;
                break;
            case binop::minus:
                const_result = l - r;
                break;
            case binop::multiply:
                const_result = l * r;
                break;
            case binop::divide:
                const_result = l / r;
                break;
            case binop::modulo:
                const_result = l % r;
                break;
        }        
    }
    else
    {
        node.lhs->accept(*this);
        auto l = value_result;
        node.rhs->accept(*this);
        auto r = value_result;
        switch(node.op)
        {
            case binop::plus:
                value_result = builder.CreateAdd(l, r);
                break;
            case binop::minus:
                value_result = builder.CreateSub(l, r);
                break;
            case binop::multiply:
                value_result = builder.CreateMul(l, r);
                break;
            case binop::divide:
                value_result = builder.CreateSDiv(l, r);
                break;
            case binop::modulo:
                value_result = builder.CreateSRem(l, r);
                break;
        }
    }
    return;
}

void assembly_builder::visit(unaryop_expr_syntax &node)
{
    if(constexpr_expected)
    {
        node.rhs->accept(*this);
        auto r = const_result;
        switch(node.op)
        {
            case unaryop::plus:
                const_result = r;
                break;
            case unaryop::minus:
                const_result = -r;
                break;
        }
    }
    else
    {
        node.rhs->accept(*this);
        auto r = value_result;
        auto zero = ConstantInt::get(Type::getInt32Ty(context), 0);
        switch(node.op)
        {
            case unaryop::plus:
                value_result = builder.CreateAdd(zero, r);
                break;
            case unaryop::minus:
                value_result = builder.CreateSub(zero, r);
                break;
        }
    }
    return;
}

void assembly_builder::visit(lval_syntax &node)
{
    auto var = lookup_variable(node.name);
    auto lv = std::get<0>(var);
    if(constexpr_expected)
    {
        err.error(node.line, node.pos, "Constant expression expected.");
        error_flag = true;
        return;
    }
    if(!lv)
    {
        err.error(node.line, node.pos, "use of undeclared identifier '" + node.name + "'");
        error_flag = true;
        return;
    }
    if(std::get<1>(var))
    {
        err.error(node.line, node.pos, "Assigning to constant. '" + node.name + "'");
        error_flag = true;
        return;
    }
    if(node.array_index)
    {
        if(!std::get<2>(var))
        {
            err.error(node.line, node.pos, "Array used as integer variable.");
            return;            
        }
    }
    else
    {
        if(std::get<2>(var))
        {
            err.error(node.line, node.pos, "Subscripted value is not an array.");
            return;           
        }
    }
    if(lval_as_rval)
    {
        if(node.array_index)
        {
            node.array_index->accept(*this);
            value_result = builder.CreateLoad(builder.CreateInBoundsGEP(lv, {ConstantInt::get(Type::getInt32Ty(context), 0), value_result}));
        }
        else
        {
            value_result = builder.CreateLoad(lv);
        }
    }
    else
    {
        if(node.array_index)
        {
            lval_as_rval = true;
            node.array_index->accept(*this);
            value_result = builder.CreateInBoundsGEP(lv, {ConstantInt::get(Type::getInt32Ty(context), 0), value_result});
            lval_as_rval = false;
        }
        else
        {
            value_result = lv;
        }
    }
    return;
}

void assembly_builder::visit(literal_syntax &node)
{
    if(constexpr_expected)
        const_result = node.number;
    else
        value_result = ConstantInt::get(Type::getInt32Ty(context), node.number);
    return;
}

void assembly_builder::visit(var_def_stmt_syntax &node)
{
    if(in_global)
    {
        if(node.array_length)     //array
        {
            constexpr_expected = true;
            node.array_length->accept(*this);
            constexpr_expected = false;
            auto l = const_result;
            auto type = ArrayType::get(Type::getInt32Ty(context), l);
            constexpr_expected = true;
            if(node.initializers.size() > const_result)
            {
                err.warn(node.line, node.pos, "array size maybe unmatched");
            }
            auto inums = node.initializers.size();
            auto array_init = new Constant*[inums];
            for(auto i = 0; i < inums; ++i)
            {
                node.initializers[i]->accept(*this);
                array_init[i] = ConstantInt::get(Type::getInt32Ty(context), const_result);
            }
            auto ar =  ArrayRef<Constant*>(array_init, array_init + inums);
            constexpr_expected = false;
            auto ini = ConstantArray::get(type, ar);
            auto v = new GlobalVariable(*module, type, node.is_constant, GlobalValue::ExternalLinkage, ini, node.name);
            if(!declare_variable(node.name, v, node.is_constant, true))
            {
                err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
            }
        }
        else   //non-array
        {
            GlobalVariable *v;
            if(!node.initializers.empty())
            {
                constexpr_expected = true;
                node.initializers[0]->accept(*this);
                constexpr_expected = false;
                auto init = ConstantInt::get(Type::getInt32Ty(context), const_result);
                v = new GlobalVariable(*module, Type::getInt32Ty(context), node.is_constant, GlobalValue::ExternalLinkage, init, node.name);
            }
            else
            {
                v = new GlobalVariable(*module, Type::getInt32Ty(context), node.is_constant, GlobalValue::ExternalLinkage, ConstantInt::get(Type::getInt32Ty(context), 0), node.name);
            }
            if(!declare_variable(node.name, v, node.is_constant, false))
            {
                err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
            }
        }
    }
    else//not in global
    {
        if(node.array_length)//array
        {
            constexpr_expected = true;
            node.array_length->accept(*this);
            constexpr_expected = false;
            auto l = const_result;
            auto type = ArrayType::get(Type::getInt32Ty(context), l);
            auto v = builder.CreateAlloca(type, nullptr, node.name);
            if(node.initializers.size() > const_result)
            {
                err.warn(node.line, node.pos, "array size maybe unmatched");
            }
            if(!node.initializers.empty())
            {
                auto inums = node.initializers.size();
                for(auto i = 0; i < inums; ++i)
                {
                    node.initializers[i]->accept(*this);
                    auto arrayptr = builder.CreateInBoundsGEP(type, v, {ConstantInt::get(Type::getInt32Ty(context), 0),ConstantInt::get(Type::getInt32Ty(context), i)});
                    builder.CreateStore(value_result, arrayptr);
                }
            }
            if(!declare_variable(node.name, v, node.is_constant, true))
            {
                err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
            }            
        }
        else //non array
        {
            auto v = builder.CreateAlloca(Type::getInt32Ty(context), nullptr, node.name);
            if(!node.initializers.empty())
            {
                node.initializers[0]->accept(*this);               
                builder.CreateStore(value_result, v);
            }
            if(!declare_variable(node.name, v, node.is_constant, false))
            {
                err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
            }
        }
    }
}

void assembly_builder::visit(assign_stmt_syntax &node)
{
    lval_as_rval = false;
    node.target->accept(*this);
    auto t = value_result;
    lval_as_rval = true;
    node.value->accept(*this);
    auto v = value_result;
    builder.CreateStore(v, t);
    return;
}

void assembly_builder::visit(func_call_stmt_syntax &node)
{
    auto got = functions.find(node.name);
    if(got == functions.end())
    {
        err.error(node.line, node.pos, "undefined reference to '" + node.name + "'");
        error_flag = true;
    }
    else
        builder.CreateCall(got->second);
    return;
}

void assembly_builder::visit(block_syntax &node)
{
    enter_scope();
    for(auto i : node.body)
        i->accept(*this);
    exit_scope();
    return;
}

void assembly_builder::visit(if_stmt_syntax &node)
{
    node.pred->accept(*this);
    auto bbtrue = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    auto bbfalse = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    auto bbfinish = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    builder.CreateCondBr(value_result, bbtrue, bbfalse);
    builder.SetInsertPoint(bbtrue);
    node.then_body->accept(*this);
    builder.CreateBr(bbfinish);
    builder.SetInsertPoint(bbfalse);
    if(node.else_body)
        node.else_body->accept(*this);
    builder.CreateBr(bbfinish);
    builder.SetInsertPoint(bbfinish);
    return;
}

void assembly_builder::visit(while_stmt_syntax &node)
{
    auto bbtest = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    auto bbtrue = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    auto bbfinish = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    builder.CreateBr(bbtest);
    builder.SetInsertPoint(bbtest);
    node.pred->accept(*this);
    builder.CreateCondBr(value_result, bbtrue, bbfinish);
    builder.SetInsertPoint(bbtrue);
    node.body->accept(*this);
    builder.CreateBr(bbtest);
    builder.SetInsertPoint(bbfinish);
    return;
}

void assembly_builder::visit(empty_stmt_syntax &node)
{

}
