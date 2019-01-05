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
        *out << spaces() << "arg " << ident << std::endl;
}

void
PrettyPrinter::visit(AST::FuncCallArgs *args)
{
    for (auto& expr : args->exprs)
    {
        *out << spaces() << "arg" << std::endl;

        indent();
        expr->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::Entry *entry)
{
    *out << spaces() << "entry" << std::endl;
}

void
PrettyPrinter::visit(AST::Stmt *stmt)
{
    *out << spaces() << "stmt" << std::endl;
}

void
PrettyPrinter::visit(explain::AST::FuncDecl *decl)
{
    *out << spaces() << "fun " << decl->ident << std::endl;

    if (decl->args)
    {
        indent();
        *out << spaces() << "args" << std::endl;

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

    *out << std::endl;
}

void
PrettyPrinter::visit(AST::AssignmentStmt *stmt)
{
    *out << spaces() << ":= " << stmt->ident << std::endl;

    indent();
    stmt->expr->accept(*this);
    dedent();
}

void
PrettyPrinter::visit(AST::IfStmt *stmt)
{
    *out << spaces() << "if" << std::endl;

    if (stmt->cond)
    {
        indent();
        stmt->cond->accept(*this);
        dedent();
    }

    if (stmt->then)
    {
        *out << spaces() << "then" << std::endl;
        indent();
        stmt->then->accept(*this);
        dedent();
    }

    if (stmt->otherwise)
    {
        *out << spaces() << "else" << std::endl;
        indent();
        stmt->otherwise->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::WhileStmt *stmt)
{
    *out << spaces() << "while" << std::endl;

    if (stmt->cond)
    {
        indent();
        stmt->cond->accept(*this);
        dedent();
    }

    if (stmt->loop)
    {
        *out << spaces() << "do" << std::endl;
        indent();
        stmt->loop->accept(*this);
        dedent();
    }
}

void
PrettyPrinter::visit(AST::ReturnStmt *stmt)
{
    *out << spaces() << "return" << std::endl;

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
    *out << spaces() << operatorToString(stmt->op) << ' ' << stmt->ident << std::endl;
}

void
PrettyPrinter::visit(AST::Expr *expr)
{
    *out << spaces() << "expr" << std::endl;
}

void
PrettyPrinter::visit(AST::ExprBinOp *expr)
{
    *out << spaces() << operatorToString(expr->op) << std::endl;

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
    *out << spaces() << expr->ident << std::endl;
}

void
PrettyPrinter::visit(AST::ExprNumber *expr)
{
    *out << spaces() << expr->number << std::endl;
}

void
PrettyPrinter::visit(AST::ExprFuncCall *expr)
{
    *out << spaces() << "call " << expr->ident << std::endl;

    indent();
    *out << spaces() << "args" << std::endl;

    indent();
    expr->args->accept(*this);
    dedent();

    dedent();
}

void
PrettyPrinter::visit(AST::Cond *cond)
{
    *out << spaces() << "cond" << std::endl;
}

void
PrettyPrinter::visit(AST::CondUnOp *cond)
{
    *out << spaces() << operatorToString(cond->op) << std::endl;

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
    *out << spaces() << operatorToString(cond->op) << std::endl;

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
    *out << spaces() << operatorToString(cond->op) << std::endl;

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
