#include "token.h"
#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

stack *stack_create(void)
{
    stack *new_stack = (stack*) malloc(sizeof(*new_stack));
    new_stack->top = NULL;
    new_stack->len = 0;
    return new_stack;
}
void stack_free(stack *stk)
{
    assert(stk != NULL);
    while (!stack_is_empty(stk))
    {
        stack_pop(stk);
    }
    free(stk);
}

void stack_push(stack *stk, void *data)
{
    stack_node *new_node = (stack_node*) malloc(sizeof(*new_node));

    assert(stk != NULL);
    new_node->data = data;
    new_node->next = stk->top;
    stk->top = new_node;
    ++stk->len;
}
void *stack_pop(stack *stk)
{
    stack_node *tmp = stk->top;
    void *data;


    assert(stk != NULL);
    if (stack_is_empty(stk))
    {
        return NULL;
    }
    stk->top = tmp->next;
    data = tmp->data;
    free(tmp);
    --stk->len;
    return data;
}

void *stack_peek(stack *stk)
{
    assert(stk != NULL);
    if (stk->top == NULL)
    {
        return NULL;
    }
    return stk->top->data;
}
bool stack_is_empty(stack *stk)
{
    assert(stk != NULL);
    return stk->top == NULL;
}
unsigned stack_get_len(stack *stk)
{
    assert(stk != NULL);
    return stk->len;
}
