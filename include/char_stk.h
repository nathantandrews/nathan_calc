#ifndef CHAR_STK_H
#define CHAR_STK_H

typedef struct char_stk
{
    char* array_base;
    char* top;
    unsigned int len;
    unsigned int array_size;
} char_stk;

char_stk* char_stk_create(unsigned int starting_size);

char* char_stk_get_array_base(char_stk* c_stk);
char* char_stk_get_top(char_stk* c_stk);
unsigned int char_stk_get_len(char_stk* c_stk);
unsigned int char_stk_get_array_size(char_stk* c_stk);

void char_stk_set_array_base(char_stk* c_stk, char* new_array_base);
void char_stk_set_top(char_stk* c_stk, char* new_top);
void char_stk_set_len(char_stk* c_stk, unsigned int new_len);
void char_stk_set_array_size(char_stk* c_stk, unsigned int new_array_size);

void char_stk_put(char_stk* c_stk, char c);
char char_stk_pop(char_stk* c_stk);

char_stk* char_stk_resize(char_stk* c_stk, unsigned int new_size);

void char_stk_destroy(char_stk* c_stk);

#endif