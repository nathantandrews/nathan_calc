#include "nta_logger.h"
#include "parser.h"
#include "token.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

LOG(parser)

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

parser *parser_new(void)
{
    parser *new_parser = (parser*) malloc(sizeof(*new_parser));

    assert(new_parser != NULL);
    memset(new_parser, 0, sizeof(*new_parser));
    return new_parser;
}
void parser_free(parser* ps)
{
    assert(ps != NULL);
    free(ps);
}

void parser_token_event(void *context, const token *t)
{
    assert(context != NULL);
    assert(t != NULL);
    parser_log_debug("token received: type: %s, value: %s\n", token_type_to_c_str(token_get_type(t)), token_get_value(t));
}
