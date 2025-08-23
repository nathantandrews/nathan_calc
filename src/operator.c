#include "operator.h"

#include <stdio.h>

#define OPERATORS_LEN 7

const char OPERATORS[] = "()^*/+-,=";

bool is_operator(char c)
{
    int i;
    for (i = 0; i < OPERATORS_LEN; ++i)
    {
        if (c == OPERATORS[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

void operator_print(calc_operator op)
{
    switch (op)
    {
        case CALC_OPERATOR_L_PAREN:
        {
            printf("(");
            break;
        }
        case CALC_OPERATOR_R_PAREN:
        {
            printf(")");
            break;
        }
        case CALC_OPERATOR_POW:
        {
            printf("^");
            break;
        }
        case CALC_OPERATOR_MUL:
        {
            printf("*");
            break;
        }
        case CALC_OPERATOR_DIV:
        {
            printf("/");
            break;
        }
        case CALC_OPERATOR_ADD:
        {
            printf("+");
            break;
        }
        case CALC_OPERATOR_SUB:
        {
            printf("-");
            break;
        }
        default:
        {
            printf("ERROR: NO OPERATOR\n");
            break;
        }
    }
}