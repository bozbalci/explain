#ifndef EXPLAIN_ASTROOT_H
#define EXPLAIN_ASTROOT_H

#include "ASTNode.h"
#include "Entry.h"

namespace explain {

class ASTRoot : public ASTNode
{
    EntryList entries;
public:
    ASTRoot();
    ~ASTRoot() override;

    llvm::Value *generateCode() override;

    std::string toString() override;

    void accept(Visitor &) override;

    void addEntry(Entry *);
};

}

#endif //EXPLAIN_ASTROOT_H
