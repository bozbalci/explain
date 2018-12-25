#include "ASTRoot.h"

namespace explain {

ASTRoot::ASTRoot() = default;

ASTRoot::~ASTRoot() = default;

llvm::Value *
ASTRoot::generateCode()
{
    return nullptr;
}

std::string
ASTRoot::toString()
{
    return "root";
}

void
ASTRoot::accept(Visitor& visitor)
{
    visitor.visit(this);
}

void
ASTRoot::addEntry(Entry *entry)
{
   entries.push_back(entry);
}

}