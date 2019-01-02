#include "ast.hh"

namespace explain {

namespace AST {

void
Entry::print(int level)
{
    Node::indent(level);
    std::cout << "Entry" << std::endl;
}

void
Root::print(int level)
{
    for (auto& e : funcDecls)
    {
        e->print(level);
    }

    Node::indent(level);
    std::cout << "Main" << std::endl;

    for (auto& s : topLevelStmts)
    {
        s->print(level + 1);
    }
}

void
Stmt::print(int level)
{
    Node::indent(level);
    std::cout << "Stmt" << std::endl;
}

bool
Stmt::validAtTopLevel()
{
    return false;
}

void
BlockStmt::print(int level)
{
    for (auto &s : stmts)
    {
        s->print(level);
    }
}

void
FuncDecl::print(int level)
{
    Node::indent(level);
    std::cout << "Func " << ident << std::endl;

    if (args)
    {
        Node::indent(level + 1);
        std::cout << "Args" << std::endl;
        args->print(level + 2);
    }

    if (body)
    {
        body->print(level + 1);
    }

    Node::indent(level);
    std::cout << "End Func" << std::endl;
}

bool
FuncDecl::validAtTopLevel()
{
    return true;
}

void
AssignmentStmt::print(int level)
{
    Node::indent(level);
    std::cout << ":=" << std::endl;
    Node::indent(level + 1);
    std::cout << ident << std::endl;
    expr->print(level + 1);
}

void
IfStmt::print(int level)
{
    Node::indent(level);
    std::cout << "If" << std::endl;

    if (cond)
    {
        cond->print(level + 1);
    }

    if (then)
    {
        Node::indent(level);
        std::cout << "Then" << std::endl;
        then->print(level + 1);
    }

    if (otherwise)
    {
        Node::indent(level);
        std::cout << "Else" << std::endl;
        otherwise->print(level + 1);
    }

    Node::indent(level);
    std::cout << "End If" << std::endl;
}

void
WhileStmt::print(int level)
{
    Node::indent(level);
    std::cout << "While" << std::endl;

    if (cond)
    {
        cond->print(level + 1);
    }

    if (loop)
    {
        Node::indent(level);
        std::cout << "Do" << std::endl;
        loop->print(level + 1);
    }

    Node::indent(level);
    std::cout << "End While" << std::endl;
}

void
ReturnStmt::print(int level)
{
    Node::indent(level);
    std::cout << "Return" << std::endl;

    if (expr)
    {
        expr->print(level + 1);
    }
}

void
IOStmt::print(int level)
{
    Node::indent(level);

    switch (op)
    {
        case Operator::INPUT:
            std::cout << "Input " << ident << std::endl;
            break;
        case Operator::OUTPUT:
            std::cout << "Output " << ident << std::endl;
            break;
        default:
            std::cout << "Malformed IOStmt" << std::endl;
            break;
    }
}

void
Expr::print(int level)
{
    Node::indent(level);
    std::cout << "Expr" << std::endl;
}

void
ExprBinOp::print(int level)
{
    Node::indent(level);

    switch (op)
    {
        case Operator::PLUS:
            std::cout << "+" << std::endl;
            break;
        case Operator::MINUS:
            std::cout << "-" << std::endl;
            break;
        case Operator::TIMES:
            std::cout << "*" << std::endl;
            break;
        case Operator::DIV:
            std::cout << "/" << std::endl;
            break;
        default:
            std::cout << "Malformed ExprBinOp" << std::endl;
    }

    if (lhs)
    {
        lhs->print(level + 1);
    }

    if (rhs)
    {
        rhs->print(level + 1);
    }
}

void
ExprIdent::print(int level)
{
    Node::indent(level);
    std::cout << "ExprIdent " << ident << std::endl;
}

void
ExprNumber::print(int level)
{
    Node::indent(level);
    std::cout << "ExprNumber " << number << std::endl;
}

void
ExprFuncCall::print(int level)
{
    Node::indent(level);
    std::cout << "ExprFuncCall " << ident << std::endl;
    Node::indent(level + 1);
    std::cout << "Args" << std::endl;
    args->print(level + 2);
}

void
Cond::print(int level)
{
    Node::indent(level);
    std::cout << "Cond" << std::endl;
}

void
CondUnOp::print(int level)
{
    Node::indent(level);

    switch (op)
    {
        case Operator::NOT:
            std::cout << "!" << std::endl;
            break;
        default:
            std::cout << "Malformed CondUnOp" << std::endl;
    }

    if (cond)
    {
        cond->print(level + 1);
    }
}

void
CondBinOp::print(int level)
{
    Node::indent(level);

    switch (op)
    {
        case Operator::AND:
            std::cout << "and" << std::endl;
            break;
        case Operator::OR:
            std::cout << "or" << std::endl;
            break;
        default:
            std::cout << "Malformed CondBinOp" << std::endl;
    }

    if (lhs)
    {
        lhs->print(level + 1);
    }

    if (rhs)
    {
        rhs->print(level + 1);
    }
}

void
CondCompOp::print(int level)
{
    Node::indent(level);

    switch (op)
    {
        case Operator::LTEQ:
            std::cout << "<=" << std::endl;
            break;
        case Operator::LT:
            std::cout << "<" << std::endl;
            break;
        case Operator::EQ:
            std::cout << "==" << std::endl;
            break;
        case Operator::GTEQ:
            std::cout << ">=" << std::endl;
            break;
        case Operator::GT:
            std::cout << ">" << std::endl;
            break;
        default:
            std::cout << "Malformed CondCompOp" << std::endl;
    }

    if (lhs)
    {
        lhs->print(level + 1);
    }

    if (rhs)
    {
        rhs->print(level + 1);
    }
}

void
FuncDeclArgs::print(int level)
{
    for (const auto &ident : idents)
    {
        Node::indent(level);
        std::cout << "Arg " << ident << std::endl;
    }
}

void
FuncCallArgs::print(int level)
{
    for (const auto &expr : exprs)
    {
        Node::indent(level);
        std::cout << "Arg" << std::endl;
        expr->print(level + 1);
    }
}

} // end namespace AST
} // end namespace explain
