#ifndef EXPLAIN_ENTRY_H

#include "ASTNode.h"

namespace explain {

class Entry : public ASTNode
{
public:
    Entry();
    ~Entry() override;

    llvm::Value *generateCode() override;
    std::string toString() override;

    void accept(Visitor &) override;
};

}

#define EXPLAIN_ENTRY_H

#endif //EXPLAIN_ENTRY_H
