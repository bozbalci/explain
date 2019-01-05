#include "printer.hh"

namespace explain {

std::string
PrettyPrinter::spaces()
{
    return std::string(static_cast<unsigned long>(level * 2), ' ');
}

void
PrettyPrinter::indent()
{
    level++;
}

void
PrettyPrinter::dedent()
{
    level--;
}

std::string PrettyPrinter::operatorToString(AST::Operator op)
{
    switch (op)
    {
        case AST::Operator::INPUT:
            return "input";
        case AST::Operator::OUTPUT:
            return "output";
        case AST::Operator::PLUS:
            return "+";
        case AST::Operator::MINUS:
            return "-";
        case AST::Operator::TIMES:
            return "*";
        case AST::Operator::DIV:
            return "/";
        case AST::Operator::NOT:
            return "!";
        case AST::Operator::AND:
            return "and";
        case AST::Operator::OR:
            return "or";
        case AST::Operator::LT:
            return "<";
        case AST::Operator::LTEQ:
            return "<=";
        case AST::Operator::EQ:
            return "==";
        case AST::Operator::GTEQ:
            return ">=";
        case AST::Operator::GT:
            return ">";
    }
}

void
PrettyPrinter::visit(AST::Root *root)
{
    for (auto& e : root->funcDecls)
        e->accept(*this);
}

void
PrettyPrinter::visit(AST::BlockStmt *block)
{
    for (auto& e : block->stmts)
        e->accept(*this);
}

void
PrettyPrinter::visit(AST::FuncDeclArgs *args)
{
    for (auto &ident : args->idents)
        std::cout << spaces() << "arg " << ident << std::endl;
}

void
PrettyPrinter::visit(AST::FuncCallArgs *args)
{
    for (auto& expr : args->exprs)
    {
        std::cout << spaces() << "arg" << std::endl;

        indent();
        expr->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::Entry *entry)
{
    std::cout << spaces() << "entry" << std::endl;
}

void
PrettyPrinter::visit(AST::Stmt *stmt)
{
    std::cout << spaces() << "stmt" << std::endl;
}

void
PrettyPrinter::visit(explain::AST::FuncDecl *decl)
{
    std::cout << spaces() << "fun " << decl->ident << std::endl;

    if (decl->args)
    {
        indent();
        std::cout << spaces() << "args" << std::endl;

        indent();
        decl->args->accept(*this);
        dedent();

        dedent();
    }

    if (decl->body)
    {
        indent();
        decl->body->accept(*this);
        dedent();
    }

    std::cout << std::endl;
}

void
PrettyPrinter::visit(AST::AssignmentStmt *stmt)
{
    std::cout << spaces() << ":= " << stmt->ident << std::endl;

    indent();
    stmt->expr->accept(*this);
    dedent();
}

void
PrettyPrinter::visit(AST::IfStmt *stmt)
{
    std::cout << spaces() << "if" << std::endl;

    if (stmt->cond)
    {
        indent();
        stmt->cond->accept(*this);
        dedent();
    }

    if (stmt->then)
    {
        std::cout << spaces() << "then" << std::endl;
        indent();
        stmt->then->accept(*this);
        dedent();
    }

    if (stmt->otherwise)
    {
        std::cout << spaces() << "else" << std::endl;
        indent();
        stmt->otherwise->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::WhileStmt *stmt)
{
    std::cout << spaces() << "while" << std::endl;

    if (stmt->cond)
    {
        indent();
        stmt->cond->accept(*this);
        dedent();
    }

    if (stmt->loop)
    {
        std::cout << spaces() << "do" << std::endl;
        indent();
        stmt->loop->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::ReturnStmt *stmt)
{
    std::cout << spaces() << "return" << std::endl;

    if (stmt->expr)
    {
        indent();
        stmt->expr->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::IOStmt *stmt)
{
    std::cout << spaces() << operatorToString(stmt->op) << ' ' << stmt->ident << std::endl;
}

void
PrettyPrinter::visit(AST::Expr *expr)
{
    std::cout << spaces() << "expr" << std::endl;
}

void
PrettyPrinter::visit(AST::ExprBinOp *expr)
{
    std::cout << spaces() << operatorToString(expr->op) << std::endl;

    if (expr->lhs)
    {
        indent();
        expr->lhs->accept(*this);
        dedent();
    }

    if (expr->rhs)
    {
        indent();
        expr->rhs->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::ExprIdent *expr)
{
    std::cout << spaces() << expr->ident << std::endl;
}

void
PrettyPrinter::visit(AST::ExprNumber *expr)
{
    std::cout << spaces() << expr->number << std::endl;
}

void
PrettyPrinter::visit(AST::ExprFuncCall *expr)
{
    std::cout << spaces() << "call " << expr->ident << std::endl;

    indent();
    std::cout << spaces() << "args" << std::endl;

    indent();
    expr->args->accept(*this);
    dedent();

    dedent();
}

void
PrettyPrinter::visit(AST::Cond *cond)
{
    std::cout << spaces() << "cond" << std::endl;
}

void
PrettyPrinter::visit(AST::CondUnOp *cond)
{
    std::cout << spaces() << operatorToString(cond->op) << std::endl;

    if (cond->cond)
    {
        indent();
        cond->cond->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::CondBinOp *cond)
{
    std::cout << spaces() << operatorToString(cond->op) << std::endl;

    if (cond->lhs)
    {
        indent();
        cond->lhs->accept(*this);
        dedent();
    }

    if (cond->rhs)
    {
        indent();
        cond->rhs->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::CondCompOp *cond)
{
    std::cout << spaces() << operatorToString(cond->op) << std::endl;

    if (cond->lhs)
    {
        indent();
        cond->lhs->accept(*this);
        dedent();
    }

    if (cond->rhs)
    {
        indent();
        cond->rhs->accept(*this);
        dedent();
    }
}

} // end namespace explain
