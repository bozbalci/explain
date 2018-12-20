#include "IfStatement.h"

namespace explain {

IfStatement::IfStatement(Conditional *cond, BlockStatement *blockThen, BlockStatement *blockElse)
    : cond(cond), blockThen(blockThen), blockElse(blockElse)
{
    ;
}

IfStatement::~IfStatement()
{
    delete cond;
    delete blockThen;
    delete blockElse;
}

llvm::Value *
IfStatement::generateCode()
{
    return nullptr;
}

std::string
IfStatement::toString()
{
    return "if_stmt";
}

void
IfStatement::accept(Visitor &visitor)
{
    visitor.visit(this);
}

}