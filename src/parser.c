#include "parser.h"
#include "token.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char ACCEPTED_KEYWORDS[][10] = {
    "cos",
    "sin",
    "tan",
    "arccos",
    "arcsin",
    "arctan",
    "log",
    "ln",
    "sqrt",
    "exp",
};

parser *parser_create(void)
{
    parser *new_parser = (parser*) malloc(sizeof(*new_parser));
    memset(new_parser, 0, sizeof(*new_parser));
    return new_parser;
}
void parser_destroy(parser* ps)
{
    free(ps);
}

void parser_token_event(void *context, const token *t)
{
    printf("token received: type: %s, value: %s\n", token_type_to_str(token_get_type(t)), token_get_value(t));
}