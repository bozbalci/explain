#include <utility>

#include "Identifier.h"

namespace explain {

Identifier::Identifier(std::string name)
    : name(std::move(name))
{
    ;
}

Identifier::~Identifier() = default;

llvm::Value *
Identifier::generateCode()
{
    return nullptr;
}

std::string
Identifier::toString()
{
    return name;
}

void
Identifier::accept(Visitor &visitor)
{
   visitor.visit(this);
}

}