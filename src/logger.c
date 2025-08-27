#include "logger.h"
#include "status.h"
#include "string_extras.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define LOGGER_MAX_TIME_LEN 16
#define LOGGER_MAX_FILENAME_LEN 25

static const char *get_time_str(void)
{
    time_t t;
    struct tm tmp;
    static char time_buf[LOGGER_MAX_TIME_LEN];

    time(&t);
    localtime_s(&tmp, &t);
    strftime(time_buf, LOGGER_MAX_TIME_LEN, "%Y%m%dT%H%M%S", &tmp);
    
    return time_buf;
}

static logger *const logger_p_create(void)
{
    logger *new_logger = (logger*) malloc(sizeof(*new_logger));
    char filename[LOGGER_MAX_FILENAME_LEN];

    sprintf(filename, "calc_%s.log", get_time_str());
    fopen_s(&(new_logger->f), filename, "w");
    new_logger->level = MESSAGE_TYPE_INFO;
    return new_logger;
}

static logger *logger_get(void)
{
    static logger *l = NULL;

    if (l == NULL)
    {
        l = logger_p_create();
    }
    return l;
}

void logger_set_level(message_type type)
{
    logger_get()->level = type;
}

static void logger_log(message_type message_type, const char *module, const char *message, ...)
{
    va_list args;
    const unsigned MODULE_LEN = strlen(module);
    char *module_upper = (char*) malloc(MODULE_LEN + 1);

    if (logger_get()->level > message_type)
    {
        free(module_upper);
        return;
    }
    switch (message_type)
    {
        case MESSAGE_TYPE_DEBUG: { fprintf(logger_get()->f, "### DEBUG "); break; }
        case MESSAGE_TYPE_WARNING: { fprintf(logger_get()->f, "--- WARNING "); break; }
        case MESSAGE_TYPE_ERROR: { fprintf(logger_get()->f, "!!! ERROR "); break; }
        case MESSAGE_TYPE_INFO:
        default: { fprintf(logger_get()->f, "   INFO "); break; }
    }
    
    strncpy_s(module_upper, MODULE_LEN + 1, module, MODULE_LEN);
    module_upper[MODULE_LEN] = '\0';
    string_to_upper(module_upper);
    fprintf(logger_get()->f, "[%s] ", module_upper);
    free(module_upper);

    va_start(args, message);
    vfprintf(logger_get()->f, message, args);
    va_end(args);
}

void debug(const char *module, const char *message, ...)
{
    va_list args;

    va_start(args, message);
    logger_log(MESSAGE_TYPE_DEBUG, module, message, args);
    va_end(args);
}
void info(const char *module, const char *message, ...)
{
    va_list args;

    va_start(args, message);
    logger_log(MESSAGE_TYPE_INFO, module, message, args);
    va_end(args);
}
void warning(const char *module, const char *message, ...)
{
    va_list args;

    va_start(args, message);
    logger_log(MESSAGE_TYPE_WARNING, module, message, args);
    va_end(args);
}
void error(const char *module, const char *message, ...)
{
    va_list args;

    va_start(args, message);
    logger_log(MESSAGE_TYPE_ERROR, module, message, args);
    va_end(args);
}
