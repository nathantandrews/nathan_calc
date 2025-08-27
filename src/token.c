#include "token.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

void token_init(token *t, token_type type, const char *value)
{
    t->type = type;
    strncpy_s(t->value, sizeof(*value), value, TOKEN_MAX_LEN);
}

token_type token_get_type(const token *t)
{
    assert(t != NULL);
    return t->type;
}
const char *token_get_value(const token *t)
{
    assert(t != NULL);
    return t->value;
}

const char *token_type_to_str(token_type type)
{
    switch (type)
    {
        case TOKEN_TYPE_DEFAULT: { return "DEFAULT"; }
        case TOKEN_TYPE_NUMBER: { return "NUMBER"; }
        case TOKEN_TYPE_OPERATOR: { return "OPERATOR"; }
        case TOKEN_TYPE_KEYWORD: { return "KEYWORD"; }
        default: { return "ERROR: INVALID TOKEN_TYPE"; }
    }
}
