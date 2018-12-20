#include "AssignmentStatement.h"

namespace explain {

AssignmentStatement::AssignmentStatement(Identifier *lhs, Expression *rhs)
    : lhs(lhs), rhs(rhs)
{
    ;
}

AssignmentStatement::~AssignmentStatement()
{
    delete lhs;
    delete rhs;
}

llvm::Value *
AssignmentStatement::generateCode()
{
    return nullptr;
}

std::string
AssignmentStatement::toString()
{
    return "assignment_stmt";
}

void
AssignmentStatement::accept(Visitor &visitor)
{
    visitor.visit(this);
}

}
