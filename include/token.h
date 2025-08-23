#ifndef TOKEN_H
#define TOKEN_H

#include "input_constants.h"

typedef enum token_type
{
    TOKEN_TYPE_DEFAULT,
    TOKEN_TYPE_NUMBER,
    TOKEN_TYPE_OPERATOR,
    TOKEN_TYPE_KEYWORD,
    TOKEN_TYPE_COUNT
} token_type;

typedef struct token
{
    token_type type;
    char value[TOKEN_MAX_LEN];
} token;

void token_init(token *t, token_type type, const char *value);

token_type token_get_type(const token *t);
const char *token_get_value(const token *t);

const char *token_type_to_str(token_type type);

#endif