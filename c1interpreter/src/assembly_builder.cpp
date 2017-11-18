
#include "assembly_builder.h"

#include <vector>

using namespace llvm;
using namespace c1_recognizer::syntax_tree;

void assembly_builder::visit(assembly &node)
{
    for(auto i = node.global_defs.begin(); i < node.global_defs.end(); ++i)
        (*i)->accept(*this);
    return;
}

void assembly_builder::visit(func_def_syntax &node)
{
    auto got = functions.find(node.name);
    if(got == functions.end())
    {
        current_function = Function::Create(FunctionType::get(Type::getVoidTy(context), {}, false),  GlobalValue::LinkageTypes::ExternalLinkage, node.name, module.get());
        functions.emplace(node.name, current_function);
        bb_count = 0;
        node.body->accept(*this);
        builder.CreateRetVoid();
        builder.ClearInsertionPoint();
    }
    else
    {
        err.error(node.line, node.pos, "redefinition of '" + node.name + "'");
    }
    return;
}

void assembly_builder::visit(cond_syntax &node)
{

}

void assembly_builder::visit(binop_expr_syntax &node)
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
    return;
}

void assembly_builder::visit(unaryop_expr_syntax &node)
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
    return;
}

void assembly_builder::visit(lval_syntax &node)
{
    //ignore array temporarily
    auto lv = std::get<0>(lookup_variable(node.name));
    if(!lv)
    {
        err.error(node.line, node.pos, "use of undeclared identifier '" + node.name + "'");
        return;
    }
    if(lval_as_rval)
        value_result = builder.CreateLoad(lv);
    else
        value_result = lv;
    return;
}

void assembly_builder::visit(literal_syntax &node)
{
    value_result = ConstantInt::get(Type::getInt32Ty(context), node.number);
    return;
}

void assembly_builder::visit(var_def_stmt_syntax &node)
{
}

void assembly_builder::visit(assign_stmt_syntax &node)
{
    lval_as_rval = false;
    node.target->accept(*this);
    auto t = value_result;
    lval_as_rval = true;
    node.value->accept(*this);
    auto v = value_result;
    lval_as_rval = false;
    builder.CreateStore(v, t);
    return;
}

void assembly_builder::visit(func_call_stmt_syntax &node)
{
    auto got = functions.find(node.name);
    if(got == functions.end())
        err.error(node.line, node.pos, "undefined reference to '" + node.name + "'");
    else
        builder.CreateCall(got->second);
    return;
}

void assembly_builder::visit(block_syntax &node)
{
    auto bb = BasicBlock::Create(context, "BB" + std::to_string(bb_count++), current_function);
    builder.SetInsertPoint(bb);
    for(auto i = node.body.begin(); i < node.body.end(); ++i)
        (*i)->accept(*this);
    builder.SetInsertPoint(bb);
    return;
}

void assembly_builder::visit(if_stmt_syntax &node)
{
}

void assembly_builder::visit(while_stmt_syntax &node)
{
}

void assembly_builder::visit(empty_stmt_syntax &node)
{
}
