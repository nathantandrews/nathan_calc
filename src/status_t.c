#include "status.h"
#include "token.h"

#include <stdio.h>

void status_handle_code(const status scanner_code)
{
    switch (scanner_code)
    {
        case STATUS_SUCCESS:
        {
            printf("SUCCESS\n");
            return;
        }
        case STATUS_LEXICAL_ERROR:
        {
            printf("ERROR: LEXICAL_ERROR\n");
            break;
        }
        case STATUS_SYNTAX_ERROR:
        {
            printf("ERROR: SYNTAX_ERROR\n");
            break;
        }
        case STATUS_LOGIC_ERROR:
        {
            printf("ERROR: LOGIC_ERROR\n");
            break;
        }
        case STATUS_TOKEN_MAX_LEN_ERROR:
        {
            printf("ERROR: TOKEN_MAX_LEN_ERROR\n");
            break;
        }
        case STATUS_INVALID_CHARACTER_ERROR:
        {
            printf("ERROR: INVALID_CHARACTER_ERROR\n");
            break;
        }
        default:
        {
            printf("ERROR: INVALID ERROR\n");
            break;
        }
    }
}

