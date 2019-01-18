#include "canonicalizer.hh"

#define ASSERT_EXISTS(e) \
    if (!e) \
        mi->fatal_error("malformed syntax tree")

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
    std::vector<std::string> copy = args->idents;
    std::sort(copy.begin(), copy.end());
    const auto duplicate = std::adjacent_find(copy.begin(), copy.end());

    if (duplicate != copy.end())
        mi->error("formal parameter '" + *duplicate + "' is declared more than once", &args->location);
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
    ASSERT_EXISTS(decl->args);
    ASSERT_EXISTS(decl->body);

    auto it = registeredFunctions.find(decl->ident);

    if (it != registeredFunctions.end())
    {
        mi->error("redefinition of function '" + decl->ident + "'", &decl->location);
        mi->note("previous declaration was here", it->second);

        return;
    }

    registeredFunctions.insert(std::pair<std::string, yy::location *>(decl->ident, &decl->location));
    encounteredReturnStmt = false;

    if (!decl->isXplnEntry && decl->ident == "main")
        decl->ident = mangledMain;

    decl->args->accept(*this);
    decl->body->accept(*this);

    if (!encounteredReturnStmt)
        mi->warning("function '" + decl->ident + "' is missing a return statement", &decl->location);
    encounteredReturnStmt = false;
}

void
Canonicalizer::visit(AST::AssignmentStmt *stmt)
{
    ASSERT_EXISTS(stmt->expr);

    stmt->expr->accept(*this);
}

void
Canonicalizer::visit(AST::IfStmt *stmt)
{
    ASSERT_EXISTS(stmt->cond);
    ASSERT_EXISTS(stmt->then);

    stmt->cond->accept(*this);
    stmt->then->accept(*this);

    if (stmt->otherwise)
        stmt->otherwise->accept(*this);
}

void
Canonicalizer::visit(AST::WhileStmt *stmt)
{
    ASSERT_EXISTS(stmt->cond);
    ASSERT_EXISTS(stmt->loop);

    stmt->cond->accept(*this);
    stmt->loop->accept(*this);
}

void
Canonicalizer::visit(AST::ReturnStmt *stmt)
{
    ASSERT_EXISTS(stmt->expr);

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
            mi->fatal_error("malformed syntax tree");
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
    ASSERT_EXISTS(expr->lhs);
    ASSERT_EXISTS(expr->rhs);

    switch (expr->op)
    {
        case AST::Operator::PLUS:
        case AST::Operator::MINUS:
        case AST::Operator::TIMES:
        case AST::Operator::DIV:
            break;
        default:
            mi->fatal_error("malformed syntax tree");
    }

    // Check for division by zero
    if (expr->rhs->getNodeType() == AST::NodeType::EXPR_NUMBER)
    {
        auto ExprNum = dynamic_cast<AST::ExprNumber *>(expr->rhs.get());
        if (ExprNum->number == 0)
            mi->warning("division by zero is undefined", &expr->location);
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
    ASSERT_EXISTS(expr->args);

    if (expr->ident == "main")
        expr->ident = mangledMain;

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
    ASSERT_EXISTS(cond->cond);

    switch (cond->op)
    {
        case AST::Operator::NOT:
            break;
        default:
            mi->error("malformed syntax tree");
    }

    cond->cond->accept(*this);
}

void
Canonicalizer::visit(AST::CondBinOp *cond)
{
    ASSERT_EXISTS(cond->lhs);
    ASSERT_EXISTS(cond->rhs);

    switch (cond->op)
    {
        case AST::Operator::AND:
        case AST::Operator::OR:
            break;
        default:
            mi->error("malformed syntax tree");
    }

    cond->lhs->accept(*this);
    cond->rhs->accept(*this);
}

void
Canonicalizer::visit(AST::CondCompOp *cond)
{
    ASSERT_EXISTS(cond->lhs);
    ASSERT_EXISTS(cond->rhs);

    switch (cond->op)
    {
        case AST::Operator::LT:
        case AST::Operator::LTEQ:
        case AST::Operator::EQ:
        case AST::Operator::GTEQ:
        case AST::Operator::GT:
            break;
        default:
            mi->error("malformed syntax tree");
    }

    cond->lhs->accept(*this);
    cond->rhs->accept(*this);
}

} // end namespace explain

