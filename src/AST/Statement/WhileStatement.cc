#include "WhileStatement.h"

namespace explain {

WhileStatement::WhileStatement(Conditional *cond, BlockStatement *block)
    : cond(cond), block(block)
{
    ;
}

WhileStatement::~WhileStatement()
{
    delete cond;
    delete block;
}

llvm::Value *
WhileStatement::generateCode()
{
    return nullptr;
}

std::string
WhileStatement::toString()
{
    return "while_stmt";
}

void
WhileStatement::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}