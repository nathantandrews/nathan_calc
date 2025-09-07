#ifndef NTA_ARGS_H
#define NTA_ARGS_H

#include "nta_bool.h"
#include "nta_logger.h"

typedef enum flag
{
    FLAG_DEBUG,
    FLAG_VERBOSE,
    FLAG_COUNT
} flag;

void args_get_flags(bool *flags, int argc, char **argv);

#endif /* ARGS_H */
