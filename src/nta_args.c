#include "nta_args.h"
#include "nta_logger.h"
#include "nta_bool.h"
#include "nta_string.h"
#include "status.h"

#include <string.h>
#include <stdlib.h>

LOG(args)

void args_get_flags(bool *flags, int argc, char **argv)
{
    int i;
    
    /* initialize all flags to false. */
    for (i = 0; i < FLAG_COUNT; ++i)
    {
        flags[i] = FALSE;
    }
    
    for (i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "debug"))
        {
            flags[FLAG_DEBUG] = TRUE;
        }
        else if (strcmp(argv[i], "-v"))
        {
            flags[FLAG_VERBOSE] = TRUE;
        }
    }
}
