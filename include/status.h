#ifndef STATUS_H
#define STATUS_H

typedef enum status
{
    STATUS_SUCCESS,
    STATUS_LEXICAL_ERROR,
    STATUS_SYNTAX_ERROR,
    STATUS_LOGIC_ERROR,
    STATUS_TOKEN_MAX_LEN_ERROR,
    STATUS_INVALID_CHARACTER_ERROR,
    STATUS_COUNT
} status;

const char *status_to_str(status s);

#endif
