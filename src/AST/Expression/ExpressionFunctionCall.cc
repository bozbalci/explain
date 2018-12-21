#include "ExpressionFunctionCall.h"

#include <utility>

namespace explain {

ExpressionFunctionCall::ExpressionFunctionCall(Identifier *functionIdent, ExpressionList actualParams)
    : functionIdent(functionIdent), actualParams(std::move(actualParams))
{
    ;
}

ExpressionFunctionCall::~ExpressionFunctionCall()
{
    delete functionIdent;
}

llvm::Value *
ExpressionFunctionCall::generateCode()
{
    return nullptr;
}

std::string
ExpressionFunctionCall::toString()
{
    return "func_call";
}

void
ExpressionFunctionCall::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}
