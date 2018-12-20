#include "ConditionalCompOp.h"

namespace explain {

ConditionalCompOp::ConditionalCompOp(Operator op, Expression *lhs, Expression *rhs)
        : op(op), lhs(lhs), rhs(rhs)
{
    ;
}

ConditionalCompOp::~ConditionalCompOp()
{
    delete lhs;
    delete rhs;
}

llvm::Value *
ConditionalCompOp::generateCode()
{
    return nullptr;
}

std::string
ConditionalCompOp::toString()
{
    return "cond_compop";
}

void
ConditionalCompOp::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}
