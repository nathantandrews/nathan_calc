#include "status.h"

const char *status_to_str(status s)
{
    switch (s)
    {
        case STATUS_SUCCESS:
        {
            return "STATUS_SUCCESS";
        }
        case STATUS_LEXICAL_ERROR:
        {
            return "STATUS_LEXICAL_ERROR";
        }
        case STATUS_SYNTAX_ERROR:
        {
            return "STATUS_SYNTAX_ERROR";
        }
        case STATUS_LOGIC_ERROR:
        {
            return "STATUS_LOGIC_ERROR";
        }
        case STATUS_TOKEN_MAX_LEN_ERROR:
        {
            return "STATUS_TOKEN_MAX_LEN_ERROR";
        }
        case STATUS_INVALID_CHARACTER_ERROR:
        {
            return "STATUS_INVALID_CHARACTER_ERROR";
        }
        case STATUS_COUNT:
        {
            return "STATUS_COUNT";
        }
        default:
        {
            return "UNKNOWN_STATUS";
        }
    }
}
