#ifndef PARSER_H
#define PARSER_H
/*parse tokens and keep state of whats expected for valid expression*/

#include "token.h"
#include "token_stk.h"

typedef struct parser
{
    int state;
    token_stk stk;
} parser;

parser *parser_create(void);
void parser_destroy(parser *ps);

void parser_token_event(void *context, const token *t);

#endif