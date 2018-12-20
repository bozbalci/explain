#ifndef EXPLAIN_OPERATOR_H
#define EXPLAIN_OPERATOR_H

namespace explain {

enum class Operator
{
    // Logical operators
    NOT,
    AND,
    OR,

    // Comparison operators
    LT,
    LTEQ,
    EQ,
    GTEQ,
    GT,

    // Arithmetic operators
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,

    // Input-output operators
    INPUT,
    OUTPUT
};

}

#endif //EXPLAIN_OPERATOR_H
