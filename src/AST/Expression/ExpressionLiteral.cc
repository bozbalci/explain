#include "ExpressionLiteral.h"

namespace explain {

ExpressionLiteral::ExpressionLiteral(double value)
    : value(value)
{
    ;
}

ExpressionLiteral::~ExpressionLiteral() = default;

llvm::Value *
ExpressionLiteral::generateCode() {
    return nullptr;
}

std::string
ExpressionLiteral::toString() {
    return "expr_literal: " + std::to_string(value);
}

void
ExpressionLiteral::accept(Visitor& visitor) {
    visitor.visit(this);
}

}