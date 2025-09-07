#include "nta_stack.h"
#include "nta_logger.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

LOG(stack)

stack *stack_new(void)
{
    stack *stk = (stack*) malloc(sizeof(*stk));

    assert(stk != NULL);
    stk->top = NULL;
    stk->len = 0;
    return stk;
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
    stack_node *new_node;

    assert(stk != NULL);
    new_node = (stack_node*) malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->next = stk->top;
    stk->top = new_node;
    ++stk->len;
}
void *stack_pop(stack *stk)
{
    stack_node *tmp;
    void *data;

    assert(stk != NULL);
    tmp = stk->top;
    if (stack_is_empty(stk))
    {
        stack_log_warning("stack_pop: stack empty, returning NULL.\n");
        return NULL;
    }
    stk->top = tmp->next;
    data = tmp->data;
    free(tmp);
    --stk->len;
    return data;
}

void *stack_peek(const stack *stk)
{
    assert(stk != NULL);
    if (stk->top == NULL)
    {
        stack_log_warning("stack_peek: stack empty, returning NULL.\n");
        return NULL;
    }
    return stk->top->data;
}
bool stack_is_empty(const stack *stk)
{
    assert(stk != NULL);
    return stk->top == NULL;
}
unsigned stack_get_len(const stack *stk)
{
    assert(stk != NULL);
    return stk->len;
}