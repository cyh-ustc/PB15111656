
#include "syntax_tree_builder.h"
#include <memory>

using namespace c1_recognizer;
using namespace c1_recognizer::syntax_tree;

syntax_tree_builder::syntax_tree_builder(error_reporter &_err) : err(_err) {}

antlrcpp::Any syntax_tree_builder::visitCompilationUnit(C1Parser::CompilationUnitContext *ctx)
{
    auto result = new assembly;
    int i,j;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    auto decls = ctx->decl();
    for(i=0;i<decls.size();++i)
    {
        if(decls[i]->vardecl())
        {
            auto vardefs = decls[i]->vardecl()->vardef();
            for(j=0;j<vardefs.size();++j)
                result->global_defs.emplace_back(visit(vardefs[j]).as<var_def_stmt_syntax *>());
        }
        if(decls[i]->constdecl())
        {
            auto constdefs = decls[i]->constdecl()->constdef();
            if(!decls[i]->constdecl()->Int())
                err.warn(decls[i]->constdecl()->Const()->getSymbol()->getLine(), decls[i]->constdecl()->Const()->getSymbol()->getCharPositionInLine(), "Concrete type missing for const declaration; integer assumed.");
            for(j=0;j<constdefs.size();++j)
                result->global_defs.emplace_back(visit(constdefs[j]).as<var_def_stmt_syntax *>());

                
        }
    }
    auto funcdefs = ctx->funcdef();
    for(i=0;i<funcdefs.size();++i)
    result->global_defs.emplace_back(visit(funcdefs[i]).as<func_def_syntax *>());

    return static_cast<assembly *>(result);
}

antlrcpp::Any syntax_tree_builder::visitDecl(C1Parser::DeclContext *ctx)
{

}

antlrcpp::Any syntax_tree_builder::visitConstdecl(C1Parser::ConstdeclContext *ctx)
{

}

antlrcpp::Any syntax_tree_builder::visitConstdef(C1Parser::ConstdefContext *ctx)
{
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = true;
    result->name = ctx->Identifier()->getSymbol()->getText();
    if(ctx->LeftBracket())
    {
        int count = 0;
        if(ctx->exp().size()-ctx->Comma().size()==2)
        {
            result->array_length.reset(visit(ctx->exp()[count]).as<expr_syntax *>());
            count++;
            for(;count<ctx->exp().size();++count)
                result->initializers.emplace_back(visit(ctx->exp()[count]).as<expr_syntax *>());
        }
        else
        {
            for(;count<ctx->exp().size();++count)
                result->initializers.emplace_back(visit(ctx->exp()[count]).as<expr_syntax *>());
            auto arraylength = new literal_syntax;
            arraylength->line = ctx->LeftBracket()->getSymbol()->getLine();
            arraylength->pos = ctx->LeftBracket()->getSymbol()->getCharPositionInLine();
            arraylength->number = result->initializers.size();
            result->array_length.reset(static_cast<expr_syntax *>(arraylength));
        }
    }
    else
    {
        result->initializers.emplace_back(visit(ctx->exp()[0]).as<expr_syntax *>());
    }
    return static_cast<var_def_stmt_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitVardecl(C1Parser::VardeclContext *ctx)
{

}

antlrcpp::Any syntax_tree_builder::visitVardef(C1Parser::VardefContext *ctx)
{
    auto result = new var_def_stmt_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->is_constant = false;
    result->name = ctx->Identifier()->getSymbol()->getText();
    if(ctx->Assign())
    {
        if(ctx->LeftBracket())
        {
            int count = 0;
            if(ctx->exp().size()-ctx->Comma().size()==2)
            {
                result->array_length.reset(visit(ctx->exp()[count]).as<expr_syntax *>());
                count++;
                for(;count<ctx->exp().size();++count)
                    result->initializers.emplace_back(visit(ctx->exp()[count]).as<expr_syntax *>());
            }
            else
            {
                for(;count<ctx->exp().size();++count)
                    result->initializers.emplace_back(visit(ctx->exp()[count]).as<expr_syntax *>());
                auto arraylength = new literal_syntax;
                arraylength->line = ctx->LeftBracket()->getSymbol()->getLine();
                arraylength->pos = ctx->LeftBracket()->getSymbol()->getCharPositionInLine();
                arraylength->number = result->initializers.size();
                result->array_length.reset(static_cast<expr_syntax *>(arraylength));
            }
        }
        else
        {
            result->initializers.emplace_back(visit(ctx->exp()[0]).as<expr_syntax *>());
        }
    }
    else
    {
        if(ctx->LeftBracket())
            result->array_length.reset(visit(ctx->exp()[0]).as<expr_syntax *>());
    }
    return static_cast<var_def_stmt_syntax *>(result);

}

antlrcpp::Any syntax_tree_builder::visitFuncdef(C1Parser::FuncdefContext *ctx)
{
    auto result = new func_def_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getSymbol()->getText();
    result->body.reset(visit(ctx->block()).as<block_syntax *>());
    return static_cast<func_def_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitBlock(C1Parser::BlockContext *ctx)
{
    auto result = new block_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    auto decls = ctx->decl();
    int i,j;
    for(i=0;i<decls.size();++i)
    {
        if(decls[i]->vardecl())
        {
            auto vardefs = decls[i]->vardecl()->vardef();
            for(j=0;j<vardefs.size();++j)
                result->body.emplace_back(visit(vardefs[j]).as<var_def_stmt_syntax *>());
        }
        if(decls[i]->constdecl())
        {
            auto constdefs = decls[i]->constdecl()->constdef();
            if(!decls[i]->constdecl()->Int())
                err.warn(decls[i]->constdecl()->Const()->getSymbol()->getLine(), decls[i]->constdecl()->Const()->getSymbol()->getCharPositionInLine(), "Concrete type missing for const declaration; integer assumed.");
            for(j=0;j<constdefs.size();++j)
                result->body.emplace_back(visit(constdefs[j]).as<var_def_stmt_syntax *>());
        }
    }
    auto stmts = ctx->stmt();
    for(i=0;i<stmts.size();++i)
    {
        result->body.emplace_back(visit(stmts[i]).as<stmt_syntax *>());
    }
    return static_cast<block_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitStmt(C1Parser::StmtContext *ctx)
{
    if(ctx->lval())
    {
        auto result = new assign_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->target.reset(visit(ctx->lval()).as<lval_syntax *>());
        result->value.reset(visit(ctx->exp()).as<expr_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->Identifier())
    {
        auto result = new func_call_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->name = ctx->Identifier()->getSymbol()->getText();
        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->block())
    {
        return static_cast<stmt_syntax *>(visit(ctx->block()).as<block_syntax *>());
    }
    if(ctx->If())
    {
        auto result = new if_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->then_body.reset(visit(ctx->stmt()[0]).as<stmt_syntax *>());
        if(ctx->Else())
        result->else_body.reset(visit(ctx->stmt()[1]).as<stmt_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }
    if(ctx->While())
    {
        auto result = new while_stmt_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        result->pred.reset(visit(ctx->cond()).as<cond_syntax *>());
        result->body.reset(visit(ctx->stmt()[0]).as<stmt_syntax *>());
        return static_cast<stmt_syntax *>(result);
    }
    auto result = new empty_stmt_syntax;
    return static_cast<stmt_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitLval(C1Parser::LvalContext *ctx)
{
    auto result = new lval_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->name = ctx->Identifier()->getSymbol()->getText();
    if(auto expression = ctx->exp())
    {
        result->array_index.reset(visit(expression).as<expr_syntax *>());
    }
    return static_cast<lval_syntax *>(result);
}

antlrcpp::Any syntax_tree_builder::visitCond(C1Parser::CondContext *ctx)
{
    auto result = new cond_syntax;
    result->line = ctx->getStart()->getLine();
    result->pos = ctx->getStart()->getCharPositionInLine();
    result->lhs.reset(visit(ctx->exp()[0]).as<expr_syntax *>());
    if(ctx->Equal())
        result->op = relop::equal;
    if(ctx->NonEqual())
        result->op = relop::non_equal;
    if(ctx->Less())
        result->op = relop::less;
    if(ctx->Greater())
        result->op = relop::greater;
    if(ctx->LessEqual())
        result->op = relop::less_equal;
    if(ctx->GreaterEqual())
        result->op = relop::greater_equal; 
    result->rhs.reset(visit(ctx->exp()[1]).as<expr_syntax *>());
    return static_cast<cond_syntax *>(result);
}

// Returns antlrcpp::Any, which is constructable from any type.
// However, you should be sure you use the same type for packing and depacking the `Any` object.
// Or a std::bad_cast exception will rise.
// This function always returns an `Any` object containing a `expr_syntax *`.
antlrcpp::Any syntax_tree_builder::visitExp(C1Parser::ExpContext *ctx)
{
    // Get all sub-contexts of type `exp`.
    auto expressions = ctx->exp();
    // Two sub-expressions presented: this indicates it's a expression of binary operator, aka `binop`.
    if (expressions.size() == 2)
    {
        auto result = new binop_expr_syntax;
        // Set line and pos.
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        // visit(some context) is equivalent to calling corresponding visit method; dispatching is done automatically
        // by ANTLR4 runtime. For this case, it's equivalent to visitExp(expressions[0]).
        // Use reset to set a new pointer to a std::shared_ptr object. DO NOT use assignment; it won't work.
        // Use `.as<Type>()' to get value from antlrcpp::Any object; notice that this Type must match the type used in
        // constructing the Any object, which is constructed from (usually pointer to some derived class of
        // syntax_node, in this case) returning value of the visit call.
        result->lhs.reset(visit(expressions[0]).as<expr_syntax *>());
        // Check if each token exists.
        // Returnd value of the calling will be nullptr (aka NULL in C) if it isn't there; otherwise non-null pointer.
        if (ctx->Plus())
            result->op = binop::plus;
        if (ctx->Minus())
            result->op = binop::minus;
        if (ctx->Multiply())
            result->op = binop::multiply;
        if (ctx->Divide())
            result->op = binop::divide;
        if (ctx->Modulo())
            result->op = binop::modulo;
        result->rhs.reset(visit(expressions[1]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // Otherwise, if `+` or `-` presented, it'll be a `unaryop_expr_syntax`.
    if (ctx->Plus() || ctx->Minus())
    {
        auto result = new unaryop_expr_syntax;
        result->line = ctx->getStart()->getLine();
        result->pos = ctx->getStart()->getCharPositionInLine();
        if (ctx->Plus())
            result->op = unaryop::plus;
        if (ctx->Minus())
            result->op = unaryop::minus;
        result->rhs.reset(visit(expressions[0]).as<expr_syntax *>());
        return static_cast<expr_syntax *>(result);
    }
    // In the case that `(` exists as a child, this is an expression like `'(' expressions[0] ')'`.
    if (ctx->LeftParen())
        return visit(expressions[0]); // Any already holds expr_syntax* here, no need for dispatch and re-patch with casting.

    if (auto lv = ctx->lval())
    {
        return static_cast<expr_syntax *>(visit(lv).as<lval_syntax *>());
    }


    // If `Number` exists as a child, we can say it's a literal integer expression.
    if (auto number = ctx->Number())
    {
        auto result = new literal_syntax;
        result->line = number->getSymbol()->getLine();
        result->pos = number->getSymbol()->getCharPositionInLine();
        auto text = number->getSymbol()->getText();
        if (text[0] == '0' && text[1] == 'x')              // Hexadecimal
            result->number = std::stoi(text, nullptr, 16); // std::stoi will eat '0x'
        else                                               // Decimal
            result->number = std::stoi(text, nullptr, 10);
        return static_cast<expr_syntax *>(result);
    }
}

ptr<syntax_tree_node> syntax_tree_builder::operator()(antlr4::tree::ParseTree *ctx)
{
    auto result = visit(ctx);
    if (result.is<syntax_tree_node *>())
        return ptr<syntax_tree_node>(result.as<syntax_tree_node *>());
    if (result.is<assembly *>())
        return ptr<syntax_tree_node>(result.as<assembly *>());
    if (result.is<global_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<global_def_syntax *>());
    if (result.is<func_def_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_def_syntax *>());
    if (result.is<cond_syntax *>())
        return ptr<syntax_tree_node>(result.as<cond_syntax *>());
    if (result.is<expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<expr_syntax *>());
    if (result.is<binop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<binop_expr_syntax *>());
    if (result.is<unaryop_expr_syntax *>())
        return ptr<syntax_tree_node>(result.as<unaryop_expr_syntax *>());
    if (result.is<lval_syntax *>())
        return ptr<syntax_tree_node>(result.as<lval_syntax *>());
    if (result.is<literal_syntax *>())
        return ptr<syntax_tree_node>(result.as<literal_syntax *>());
    if (result.is<stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<stmt_syntax *>());
    if (result.is<var_def_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<var_def_stmt_syntax *>());
    if (result.is<assign_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<assign_stmt_syntax *>());
    if (result.is<func_call_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<func_call_stmt_syntax *>());
    if (result.is<block_syntax *>())
        return ptr<syntax_tree_node>(result.as<block_syntax *>());
    if (result.is<if_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<if_stmt_syntax *>());
    if (result.is<while_stmt_syntax *>())
        return ptr<syntax_tree_node>(result.as<while_stmt_syntax *>());
    return nullptr;
}
