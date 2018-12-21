#include "ActualParameterList.h"

namespace explain {

ActualParameterList::ActualParameterList() = default;

ActualParameterList::~ActualParameterList() = default;

llvm::Value *
ActualParameterList::generateCode() {
    return nullptr;
}

std::string
ActualParameterList::toString() {
    return std::string();
}

void
ActualParameterList::accept(Visitor& visitor) {
    visitor.visit(this);
}

void
ActualParameterList::addParameter(Expression *param) {
    actualParams.push_back(param);
}

}