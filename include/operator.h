#ifndef OPERATOR_H
#define OPERATOR_H

typedef enum operator_t
{
    ADD = 0,
    SUB = 1,
    MUL = 2,
    DIV = 3
} operator_t;

void operator_print(operator_t op);

#endif