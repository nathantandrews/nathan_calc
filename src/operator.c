#include "operator.h"
#include "nta_bool.h"

const char OPERATORS[] = "()^*/+-,=";

bool is_operator(const char c)
{
    int i;
    
    for (i = 0; i < OPERATOR_MAX_LEN; ++i)
    {
        if (c == OPERATORS[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}

const char *operator_to_str(const calc_operator op)
{
    switch (op)
    {
        case CALC_OPERATOR_L_PAREN: { return "("; }
        case CALC_OPERATOR_R_PAREN: { return ")"; }
        case CALC_OPERATOR_POW: { return "^"; }
        case CALC_OPERATOR_MUL: { return "*"; }
        case CALC_OPERATOR_DIV: { return "/"; }
        case CALC_OPERATOR_ADD: { return "+"; }
        case CALC_OPERATOR_SUB: { return "-"; }
        default: { return "ERROR: NO OPERATOR"; }
    }
}