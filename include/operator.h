#ifndef OPERATOR_H
#define OPERATOR_H

#include "bool.h"

typedef enum calc_operator
{
    CALC_OPERATOR_L_PAREN,
    CALC_OPERATOR_R_PAREN,
    CALC_OPERATOR_POW,
    CALC_OPERATOR_MUL,
    CALC_OPERATOR_DIV,
    CALC_OPERATOR_ADD,
    CALC_OPERATOR_SUB,
    CALC_OPERATOR_COUNT
} calc_operator;

bool is_operator(char *s);
const char *operator_to_str(calc_operator op);

#endif