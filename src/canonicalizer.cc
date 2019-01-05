#include "canonicalizer.hh"

#include <vector>

namespace explain
{

void
Canonicalizer::visit(AST::Root *root)
{
    // We will modify the AST by creating a `FuncDecl` node for the top level statements. This will be the entry point
    // for XPLN programs.
    auto mainFuncBody = std::make_unique<AST::BlockStmt>(std::move(root->topLevelStmts));
    auto mainFuncArgs = std::make_unique<AST::FuncDeclArgs>();
    auto mainFuncDecl = std::make_unique<AST::FuncDecl>("xpln_main", std::move(mainFuncArgs), std::move(mainFuncBody));
    mainFuncDecl->isXplnEntry = true;
    root->funcDecls.push_back(std::move(mainFuncDecl));

    // Now that `topLevelStmts` are dealt with, we can proceed by canonicalizing each function declaration.
    for (auto& f : root->funcDecls)
        f->accept(*this);
}

void
Canonicalizer::visit(AST::BlockStmt *block)
{
    // For each `BlockStmt`, we will prune AST nodes that occur after a `ReturnStmt` node to simplify code generation.
    bool prune = false;

    for (auto it = block->stmts.begin(); it != block->stmts.end(); )
    {
        if (prune)
            it = block->stmts.erase(it);
        else
        {
            it->get()->accept(*this);

            if (it->get()->getNodeType() == AST::NodeType::RETURN_STMT)
                prune = true;

            it++;
        }
    }
}

void
Canonicalizer::visit(AST::FuncDeclArgs *args)
{
    ;
}

void
Canonicalizer::visit(AST::FuncCallArgs *args)
{
    for (auto& expr : args->exprs)
        expr->accept(*this);
}

void
Canonicalizer::visit(AST::Entry *entry)
{
    ;
}

void
Canonicalizer::visit(AST::Stmt *stmt)
{
    ;
}

void
Canonicalizer::visit(AST::FuncDecl *decl)
{
    encounteredReturnStmt = false;

    if (!decl->isXplnEntry && decl->ident == "main")
        decl->ident = mangledMain;

    if (!decl->args)
    {
        mi->error("missing FuncDeclArgs in FuncDecl");

        return;
    }
    decl->args->accept(*this);

    if (!decl->body)
    {
        mi->error("missing BlockStmt in FuncDecl");

        return;
    }
    decl->body->accept(*this);

    if (!encounteredReturnStmt)
    {
        mi->error("no ReturnStmt inside block of FuncDecl");

        return;
    }

    encounteredReturnStmt = false;
}

void
Canonicalizer::visit(AST::AssignmentStmt *stmt)
{
    if (!stmt->expr)
    {
        mi->error("missing Expr in AssignmentStmt");

        return;
    }
    stmt->expr->accept(*this);
}

void
Canonicalizer::visit(AST::IfStmt *stmt)
{
    if (!stmt->cond)
    {
        mi->error("missing Cond in IfStmt");

        return;
    }
    stmt->cond->accept(*this);

    if (!stmt->then)
    {
        mi->error("missing BlockStmt (`then`) in IfStmt");

        return;
    }
    stmt->then->accept(*this);

    if (stmt->otherwise)
        stmt->otherwise->accept(*this);
}

void
Canonicalizer::visit(AST::WhileStmt *stmt)
{
    if (!stmt->cond)
    {
        mi->error("missing Cond in WhileStmt");

        return;
    }
    stmt->cond->accept(*this);

    if (!stmt->loop)
    {
        mi->error("missing BlockStmt in WhileStmt");

        return;
    }
    stmt->loop->accept(*this);
}

void
Canonicalizer::visit(AST::ReturnStmt *stmt)
{
    if (!stmt->expr)
    {
        mi->error("missing Expr in ReturnStmt");

        return;
    }
    stmt->expr->accept(*this);

    encounteredReturnStmt = true;
}

void
Canonicalizer::visit(AST::IOStmt *stmt)
{
    switch (stmt->op)
    {
        case AST::Operator::INPUT:
        case AST::Operator::OUTPUT:
            break;
        default:
            mi->error("invalid operator supplied to IOStmt");
    }
}

void
Canonicalizer::visit(AST::Expr *expr)
{
    ;
}

void
Canonicalizer::visit(AST::ExprBinOp *expr)
{
    switch (expr->op)
    {
        case AST::Operator::PLUS:
        case AST::Operator::MINUS:
        case AST::Operator::TIMES:
        case AST::Operator::DIV:
            break;
        default:
            mi->error("invalid operator supplied to ExprBinOp");
    }

    if (!expr->lhs || !expr->rhs)
    {
        mi->error("missing operands to ExprBinOp");

        return;
    }
    expr->lhs->accept(*this);
    expr->rhs->accept(*this);
}

void
Canonicalizer::visit(AST::ExprIdent *expr)
{
    ;
}

void
Canonicalizer::visit(AST::ExprNumber *expr)
{
    ;
}

void
Canonicalizer::visit(AST::ExprFuncCall *expr)
{
    if (expr->ident == "main")
        expr->ident = mangledMain;

    if (!expr->args)
    {
        mi->error("missing FuncCallArgs in ExprFuncCall");

        return;
    }
    expr->args->accept(*this);
}

void
Canonicalizer::visit(AST::Cond *cond)
{
    ;
}

void
Canonicalizer::visit(AST::CondUnOp *cond)
{
    switch (cond->op)
    {
        case AST::Operator::NOT:
            break;
        default:
            mi->error("invalid operator supplied to CondBinOp");
    }

    if (!cond->cond)
    {
        mi->error("missing operand to CondUnOp");

        return;
    }
    cond->cond->accept(*this);
}

void
Canonicalizer::visit(AST::CondBinOp *cond)
{
    switch (cond->op)
    {
        case AST::Operator::AND:
        case AST::Operator::OR:
            break;
        default:
            mi->error("invalid operator supplied to CondBinOp");
    }

    if (!cond->lhs || !cond->rhs)
    {
        mi->error("missing operands to CondBinOp");

        return;
    }
    cond->lhs->accept(*this);
    cond->rhs->accept(*this);
}

void
Canonicalizer::visit(AST::CondCompOp *cond)
{
    switch (cond->op)
    {
        case AST::Operator::LT:
        case AST::Operator::LTEQ:
        case AST::Operator::EQ:
        case AST::Operator::GTEQ:
        case AST::Operator::GT:
            break;
        default:
            mi->error("invalid operator supplied to CondCompOp");
    }

    if (!cond->lhs || !cond->rhs)
    {
        mi->error("missing operands to CondCompOp");

        return;
    }
    cond->lhs->accept(*this);
    cond->rhs->accept(*this);
}

} // end namespace explain

