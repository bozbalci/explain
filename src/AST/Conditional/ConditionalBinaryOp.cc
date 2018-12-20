#include "ConditionalBinaryOp.h"

namespace explain {

ConditionalBinaryOp::ConditionalBinaryOp(Operator op, Conditional *lhs, Conditional *rhs)
    : op(op), lhs(lhs), rhs(rhs)
{
    ;
}

ConditionalBinaryOp::~ConditionalBinaryOp()
{
    delete lhs;
    delete rhs;
}

llvm::Value *
ConditionalBinaryOp::generateCode()
{
    return nullptr;
}

std::string
ConditionalBinaryOp::toString()
{
    return "cond_binop";
}

void
ConditionalBinaryOp::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}
