#include "token.h"
#include "token_stk.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static token_stk *token_stk_resize(token_stk *t_stk, unsigned int new_size);



token_stk *token_stk_create(unsigned int starting_size)
{
    token_stk *new_token_stk = (token_stk*) malloc(sizeof(*new_token_stk));
    token *new_array = (token*) malloc(starting_size);
    token_stk_set_array_base(new_token_stk, new_array);
    token_stk_set_top(new_token_stk, NULL);
    token_stk_set_len(new_token_stk, 0);
    token_stk_set_array_capacity(new_token_stk, starting_size);
    return new_token_stk;
}

token *token_stk_get_array_base(token_stk *t_stk)
{
    return t_stk->array_base;
}
token *token_stk_get_top(token_stk *t_stk)
{
    return t_stk->top;
}
unsigned int token_stk_get_len(token_stk *t_stk)
{
    return t_stk->len;
}
unsigned int token_stk_get_array_capacity(token_stk *t_stk)
{
    return t_stk->array_capacity;
}
bool token_stk_is_full(token_stk *t_stk)
{
    return t_stk->len == t_stk->array_capacity? TRUE : FALSE;
}

void token_stk_set_array_base(token_stk *t_stk, token *new_array_base)
{
    free(t_stk->array_base);
    t_stk->array_base = new_array_base;
}
void token_stk_set_top(token_stk *t_stk, token *new_top)
{
    t_stk->top = new_top;
}
void token_stk_set_len(token_stk *t_stk, unsigned int new_len)
{
    t_stk->len = new_len;
}
void token_stk_set_array_capacity(token_stk *t_stk, unsigned int new_array_capacity)
{
    t_stk->array_capacity = new_array_capacity;
}

void token_stk_put(token_stk **t_stk_ptr, token* t)
{
    token_stk *t_stk = *t_stk_ptr;
    if (token_stk_is_full(t_stk))
    {
        *t_stk_ptr = token_stk_resize(t_stk, t_stk->array_capacity * 2);
    }

    if (t_stk->top == NULL)
    {
        t_stk->top = t_stk->array_base;
    }
    t_stk->len += 1;
    *(t_stk->top) = *t;
    t_stk->len += 1;
}
token token_stk_pop(token_stk *t_stk)
{
    assert(t_stk->len != 0);
    int i;
    token *iter = t_stk->array_base;
    for (i = 0; i < t_stk->len; ++i)
    {
        ++iter;
    }
    t_stk->len -= 1;
    return *iter;
}

static token_stk *token_stk_resize(token_stk *t_stk, unsigned int new_size)
{
    unsigned int i;
    token *iter;
    token *new_array;
    if (t_stk->array_capacity == new_size)
    {
        printf("In token_stk_resize, new size is equal to old size.");
        
    }
    else if (t_stk->array_capacity > new_size)
    {
        printf("In token_stk_resize, new size is less than old size.");
    }
    else
    {
        new_array = (token*) malloc(new_size);
        iter = t_stk->array_base;
        for (i = 0; i < t_stk->array_capacity; ++i)
        {
            new_array[i] = *iter;
            ++iter;
        }
        token_stk_set_array_base(t_stk, new_array);
    }
    return t_stk;
}

void token_stk_destroy(token_stk *t_stk)
{
    free(t_stk->array_base);
    free(t_stk);
}