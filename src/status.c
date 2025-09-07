#include "status.h"

const char *status_to_c_str(status s)
{
    switch (s)
    {
        case STATUS_SUCCESS: { return "STATUS_SUCCESS"; }
        
        case STATUS_LEXICAL_ERROR: { return "STATUS_LEXICAL_ERROR"; }
        case STATUS_SYNTAX_ERROR: { return "STATUS_SYNTAX_ERROR"; }
        case STATUS_LOGIC_ERROR: { return "STATUS_LOGIC_ERROR"; }

        case STATUS_FAILED_CONSTRUCTOR_ERROR: { return "STATUS_FAILED_CONSTRUCTOR_ERROR"; }
        case STATUS_FAILED_DESTRUCTOR_ERROR: { return "STATUS_FAILED_DESTRUCTOR_ERROR"; }
        case STATUS_FAILED_COPY_ERROR: { return "STATUS_FAILED_COPY_ERROR"; }

        case STATUS_LEN_EXCEEDED_ERROR: { return "STATUS_LEN_EXCEEDED_ERROR"; }
        case STATUS_INDEX_OUT_OF_BOUNDS_ERROR: { return "STATUS_INDEX_OUT_OF_BOUNDS_ERROR"; }
        case STATUS_NULL_INPUT_ERROR: { return "STATUS_NULL_INPUT_ERROR"; }
        case STATUS_INVALID_ARGUMENT_ERROR: { return "STATUS_INVALID_ARGUMENT_ERROR"; }

        case STATUS_COUNT: { return "STATUS_COUNT"; }
        default: { return "UNKNOWN_STATUS"; }
    }
}