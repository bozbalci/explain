#ifndef EXPLAIN_CONDITIONAL_H
#define EXPLAIN_CONDITIONAL_H

#include "../ASTNode.h"
#include "../../Visitor/Visitor.h"

namespace explain {

class Conditional : public ASTNode
{
public:
    void accept(Visitor& visitor) override;
};

}

#endif //EXPLAIN_CONDITIONAL_H
