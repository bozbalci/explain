#include "Expression.h"

namespace explain {

void
Expression::accept(Visitor& visitor)
{
    visitor.visit(this);
}

}

