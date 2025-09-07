#include "token.h"
#include "status.h"
#include "nta_logger.h"

#include <string.h>
#include <stdlib.h>
#include <assert.h>

LOG(token)

void token_init(token *t, token_type type, const char *value)
{
    if (strlen(value) > TOKEN_MAX_STRING_SIZE)
    {
        token_log_status(STATUS_LEN_EXCEEDED_ERROR);
    }
    t->type = type;
    strncpy(t->value, value, TOKEN_MAX_STRING_SIZE);
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

const char *token_type_to_c_str(token_type type)
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