#include "IOStatement.h"

namespace explain {

IOStatement::IOStatement(Operator op, Identifier *ident)
    : op(op), ident(ident)
{
    ;
}

IOStatement::~IOStatement()
{
    delete ident;
}

llvm::Value *
IOStatement::generateCode()
{
    return nullptr;
}

std::string
IOStatement::toString()
{
    return "io_stmt";
}

void
IOStatement::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}
