#ifndef EXPLAIN_CONDITIONAL_H
#define EXPLAIN_CONDITIONAL_H

#include "../ASTNode.h"
#include "../Misc/Operator.h"

namespace explain {

class Conditional : public ASTNode
{
public:
    void accept(Visitor& visitor) override;
};

}

#endif //EXPLAIN_CONDITIONAL_H
