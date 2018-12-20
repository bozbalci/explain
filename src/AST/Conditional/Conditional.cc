#include "Conditional.h"

namespace explain {

void
Conditional::accept(Visitor &visitor)
{
    visitor.visit(this);
}

}