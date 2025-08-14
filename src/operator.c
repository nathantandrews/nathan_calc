#include <stdio.h>

#include "operator.h"

void operator_print(operator_t op)
{
    switch (op)
    {
        case ADD:
        {
            printf("+");
        }
        case SUB:
        {
            printf("-");
        }
        case MUL:
        {
            printf("*");
        }
        case DIV:
        {
            printf("/");
        }
    }
}