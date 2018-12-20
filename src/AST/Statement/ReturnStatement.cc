#include "ReturnStatement.h"

namespace explain {

ReturnStatement::ReturnStatement(Expression *expr)
    : expr(expr)
{
    ;
}

ReturnStatement::~ReturnStatement()
{
    delete expr;
}

llvm::Value *
ReturnStatement::generateCode()
{
    return nullptr;
}

std::string
ReturnStatement::toString()
{
    return "return_stmt";
}

void
ReturnStatement::accept(Visitor &visitor)
{
    visitor.visit(this);
}

}
