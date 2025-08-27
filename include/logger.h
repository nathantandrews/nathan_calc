#ifndef LOGGER_H
#define LOGGER_H

#include "status.h"

#include <stdio.h>
#include <stdarg.h>

typedef enum message_type
{
    MESSAGE_TYPE_DEBUG,
    MESSAGE_TYPE_INFO,
    MESSAGE_TYPE_WARNING,
    MESSAGE_TYPE_ERROR,
    MESSAGE_TYPE_COUNT
} message_type;

typedef struct logger
{
    FILE *f;
    message_type level;
} logger;

void logger_set_level(message_type type);

void debug(const char *module, const char *message, ...);
void info(const char *module, const char *message, ...);
void warning(const char *module, const char *message, ...);
void error(const char *module, const char *message, ...);

#define MODULE_DEBUG(x) \
    void x##_log_debug(const char *message, ...) { va_list args; va_start(args, message); debug(#x, message, args); va_end(args); } \
    void x##_log_info(const char *message, ...) { va_list args; va_start(args, message); info(#x, message, args); va_end(args); } \
    void x##_log_warning(const char *message, ...) { va_list args; va_start(args, message); warning(#x, message, args); va_end(args); } \
    void x##_log_error(const char *message, ...) { va_list args; va_start(args, message); error(#x, message, args); va_end(args); } \
    void x##_log_status(status s) \
    { \
        switch (s) \
        { \
            case STATUS_SUCCESS: { x##_log_info(#x, "success\n"); break; } \
            default: { x##_log_error("error %u occurred at %s:%d\n", s, __FILE__, __LINE__); break; } \
        } \
    }

#endif
