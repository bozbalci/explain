#include <utility>

#include "BlockStatement.h"

namespace explain {

BlockStatement::BlockStatement(StatementList stmts)
    : stmts(std::move(stmts))
{
    ;
}

BlockStatement::~BlockStatement() = default;

llvm::Value *
BlockStatement::generateCode()
{
    return nullptr;
}

std::string
BlockStatement::toString()
{
    return "block_stmt";
}

void
BlockStatement::accept(Visitor &visitor)
{
    visitor.visit(this);
}

}