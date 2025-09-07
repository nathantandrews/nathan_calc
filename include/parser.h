#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "ast.h"
#include "nta_stack.h"

typedef struct parser
{
    int state;
    stack stk;
} parser;

parser *parser_new(void);
void parser_free(parser *ps);

void parser_token_event(void *context, const token *t);

#endif /* PARSER_H */
