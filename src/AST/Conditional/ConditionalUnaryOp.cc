#include "ConditionalUnaryOp.h"

namespace explain {

ConditionalUnaryOp::ConditionalUnaryOp(Operator op, Conditional *cond)
    : op(op), cond(cond)
{
    ;
}

ConditionalUnaryOp::~ConditionalUnaryOp()
{
    delete cond;
}

llvm::Value *
ConditionalUnaryOp::generateCode()
{
    return nullptr;
}

std::string
ConditionalUnaryOp::toString()
{
    return "cond_unop";
}

void
ConditionalUnaryOp::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}
