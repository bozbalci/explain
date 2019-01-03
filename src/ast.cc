#include "ast.hh"

namespace explain {

namespace AST {

std::string
get_op_repr(Operator op)
{
    switch (op)
    {
        case Operator::INPUT:
            return "input";
        case Operator::OUTPUT:
            return "output";
        case Operator::PLUS:
            return "+";
        case Operator::MINUS:
            return "-";
        case Operator::TIMES:
            return "*";
        case Operator::DIV:
            return "/";
        case Operator::NOT:
            return "!";
        case Operator::AND:
            return "and";
        case Operator::OR:
            return "or";
        case Operator::LT:
            return "<";
        case Operator::LTEQ:
            return "<=";
        case Operator::EQ:
            return "==";
        case Operator::GTEQ:
            return ">=";
        case Operator::GT:
            return ">";
    }
}

bool
Stmt::validAtTopLevel()
{
    return false;
}

bool
FuncDecl::validAtTopLevel()
{
    return true;
}

StatementType
AssignmentStmt::getType() {
    return StatementType::ASSIGNMENT;
}

StatementType
IfStmt::getType() {
    return StatementType::IF;
}

StatementType
WhileStmt::getType() {
    return StatementType::WHILE;
}

StatementType
ReturnStmt::getType() {
    return StatementType::RETURN;
}

StatementType
IOStmt::getType() {
    return StatementType::IO;
}

} // end namespace AST

} // end namespace explain
