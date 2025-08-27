#ifndef STACK_H
#define STACK_H

#include "bool.h"

typedef struct stack_node
{
    void *data;
    struct stack_node *next;
} stack_node;

typedef struct stack
{
    stack_node *top;
    unsigned len;
} stack;

stack *stack_create(void);
void stack_free(stack *stk);

void stack_push(stack *stk, void *data);
void *stack_pop(stack *stk);

void *stack_peek(stack *stk);
bool stack_is_empty(stack *stk);
unsigned stack_get_len(stack *stk);

#endif
