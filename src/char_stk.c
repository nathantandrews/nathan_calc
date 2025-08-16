#include <stdlib.h>

#include "char_stk.h"

char_stk* char_stk_create(unsigned int starting_size)
{
    char_stk* new_char_stk = (char_stk*) malloc(sizeof(*new_char_stk));
    char* new_array = (char*) malloc(starting_size);
    char_stk_set_array_base(new_char_stk, new_array);
    char_stk_set_top(new_char_stk, new_array);
    char_stk_set_len(new_char_stk, 0);
    char_stk_set_array_size(new_char_stk, starting_size);
    return new_char_stk;
}

char* char_stk_get_array_base(char_stk* c_stk)
{
    return c_stk->array_base;
}
char* char_stk_get_top(char_stk* c_stk)
{
    return c_stk->top;
}
unsigned int char_stk_get_len(char_stk* c_stk)
{
    return c_stk->len;
}
unsigned int char_stk_get_array_size(char_stk* c_stk)
{
    return c_stk->array_size;
}

void char_stk_set_array_base(char_stk* c_stk, char* new_array_base)
{
    free(c_stk->array_base);
    c_stk->array_base = new_array_base;
}
void char_stk_set_top(char_stk* c_stk, char* new_top)
{
    c_stk->top = new_top;
}
void char_stk_set_len(char_stk* c_stk, unsigned int new_len)
{
    c_stk->len = new_len;
}
void char_stk_set_array_size(char_stk* c_stk, unsigned int new_array_size)
{
    c_stk->array_size = new_array_size;
}

void char_stk_put(char_stk* c_stk, char c);
char char_stk_pop(char_stk* c_stk);

char_stk* char_stk_resize(char_stk* c_stk, unsigned int new_size)
{
    
}

void char_stk_destroy(char_stk* c_stk)
{
    free(c_stk->array_base);
    free(c_stk);
}