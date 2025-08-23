#ifndef TOKEN_STK_H
#define TOKEN_STK_H

#include "token.h"
#include "bool.h"

typedef struct token_stk
{
    token *array_base;
    token *top;
    unsigned int len;
    unsigned int array_capacity; /*change to capacity*/
} token_stk;

token_stk *token_stk_create(unsigned int starting_size);

token *token_stk_get_array_base(token_stk *t_stk);
token *token_stk_get_top(token_stk *t_stk);
unsigned int token_stk_get_len(token_stk *t_stk);
unsigned int token_stk_get_array_capacity(token_stk *t_stk);
bool token_stk_is_full(token_stk *t_stk);

void token_stk_set_array_base(token_stk *t_stk, token *new_array_base);
void token_stk_set_top(token_stk *t_stk, token *new_top);
void token_stk_set_len(token_stk *t_stk, unsigned int new_len);
void token_stk_set_array_capacity(token_stk *t_stk, unsigned int new_array_capacity);

void token_stk_put(token_stk **t_stk_ptr, token *t);
token token_stk_pop(token_stk *t_stk);

void token_stk_destroy(token_stk *t_stk);

#endif