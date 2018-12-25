#include "Entry.h"

namespace explain {

Entry::Entry() = default;

Entry::~Entry() = default;

llvm::Value *
Entry::generateCode() {
    return nullptr;
}

std::string
Entry::toString()
{
    return "entry";
}

void
Entry::accept(Visitor& visitor) {
    visitor.visit(this);
}

}

