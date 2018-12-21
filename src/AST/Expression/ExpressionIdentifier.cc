#include "ExpressionIdentifier.h"

namespace explain {

ExpressionIdentifier::ExpressionIdentifier(Identifier *ident)
    : ident(ident)
{
    ;
}

ExpressionIdentifier::~ExpressionIdentifier()
{
    delete ident;
}

llvm::Value *
ExpressionIdentifier::generateCode() {
    return nullptr;
}

std::string
ExpressionIdentifier::toString() {
    return "expr_ident";
}

void
ExpressionIdentifier::accept(Visitor& visitor) {
    visitor.visit(this);
}

}