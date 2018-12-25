#include "FormalParameterList.h"

namespace explain {

FormalParameterList::FormalParameterList() = default;

FormalParameterList::~FormalParameterList() = default;

llvm::Value *
FormalParameterList::generateCode() {
    return nullptr;
}

std::string
FormalParameterList::toString() {
    return std::string();
}

void
FormalParameterList::accept(Visitor& visitor) {
    visitor.visit(this);
}

void
FormalParameterList::addParameter(Identifier *param) {
    formalParams.push_back(param);
}

}