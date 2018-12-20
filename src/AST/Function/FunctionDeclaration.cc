#include <utility>

#include "FunctionDeclaration.h"

namespace explain {

FunctionDeclaration::FunctionDeclaration(Identifier *ident, IdentifierList formalArgs, BlockStatement *body)
    : ident(ident), formalArgs(std::move(formalArgs)), body(body)
{
    ;
}

FunctionDeclaration::~FunctionDeclaration()
{
    delete ident;
    delete body;
}

llvm::Value *
FunctionDeclaration::generateCode()
{
    return nullptr;
}

std::string
FunctionDeclaration::toString()
{
    return "func_decl";
}

void
FunctionDeclaration::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}