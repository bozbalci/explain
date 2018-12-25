#include <utility>

#include "BlockStatement.h"

namespace explain {

BlockStatement::BlockStatement() = default;

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

void
BlockStatement::createStatement(Statement *stmt)
{
    stmts.push_back(stmt);
}

}