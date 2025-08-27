#ifndef PARSER_H
#define PARSER_H
/*parse tokens and keep state of whats expected for valid expression*/

#include "token.h"
#include "ast.h"
#include "stack.h"

typedef struct parser
{
    int state;
    stack stk;
} parser;

parser *parser_create(void);
void parser_free(parser *ps);

void parser_token_event(void *context, const token *t);

#endif
