#ifndef EXPLAIN_IDENTIFIER_H
#define EXPLAIN_IDENTIFIER_H

#include "../ASTNode.h"

namespace explain {

class Identifier : public ASTNode
{
    std::string name;
public:
    explicit Identifier(std::string);
    ~Identifier() final;

    llvm::Value *generateCode() final;
    std::string toString() final;

    void accept(Visitor&) final;
};

}

#endif //EXPLAIN_IDENTIFIER_H
