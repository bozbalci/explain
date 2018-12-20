#include "ExpressionBinaryOp.h"

namespace explain {

ExpressionBinaryOp::ExpressionBinaryOp(Operator op, Expression *lhs, Expression *rhs)
    : op(op), lhs(lhs), rhs(rhs)
{
    ;
}

ExpressionBinaryOp::~ExpressionBinaryOp()
{
    delete lhs;
    delete rhs;
}

llvm::Value *
ExpressionBinaryOp::generateCode()
{
    return nullptr;
}

std::string
ExpressionBinaryOp::toString()
{
    return "expr_binop";
}

}
