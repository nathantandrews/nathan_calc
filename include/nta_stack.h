#ifndef NTA_STACK_H
#define NTA_STACK_H

#include "nta_bool.h"

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

stack *stack_new(void);
void stack_free(stack *stk);

void stack_push(stack *stk, void *data);
void *stack_pop(stack *stk);

void *stack_peek(const stack *stk);
bool stack_is_empty(const stack *stk);
unsigned stack_get_len(const stack *stk);

#endif /* STACK_H */
