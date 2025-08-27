#include "parser.h"
#include "token.h"
#include "logger.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

MODULE_DEBUG(parser)

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
    if (new_parser == NULL)
    {
        parser_log_error("parser not allocated, not enough memory.\n");
        return NULL;
    }
    memset(new_parser, 0, sizeof(*new_parser));
    return new_parser;
}
void parser_free(parser* ps)
{
    free(ps);
}

void parser_token_event(void *context, const token *t)
{
    parser_log_debug("token received: type: %s, value: %s\n", token_type_to_str(token_get_type(t)), token_get_value(t));
}
