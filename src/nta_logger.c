#include "nta_logger.h"
#include "nta_string.h"
#include "status.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define LOGGER_MAX_FILENAME_LEN 25
#define LOGGER_MAX_TIME_LEN 16
#define LOGGER_DEFAULT_LEVEL MESSAGE_TYPE_INFO

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

static logger *const logger_p_new(void)
{
    logger *new_logger = (logger*) malloc(sizeof(*new_logger));
    char filename[LOGGER_MAX_FILENAME_LEN];

    sprintf(filename, "calc_%s.log", get_time_str());
    fopen_s(&(new_logger->f), filename, "w");
    fprintf(new_logger->f, "    --------------------LOG START--------------------\n");
    new_logger->level = LOGGER_DEFAULT_LEVEL;
    return new_logger;
}

static logger *logger_get(void)
{
    static logger *l = NULL;

    if (l == NULL)
    {
        l = logger_p_new();
    }
    return l;
}

void logger_free(void)
{
    logger *l = logger_get();
    fclose(l->f);
    free(l);
}

static void logger_set_level(message_type type)
{
    logger_get()->level = type;
}

void logger_set_debug(bool b)
{
    logger_set_level(b ? MESSAGE_TYPE_DEBUG : MESSAGE_TYPE_INFO);
}

static void logger_log(message_type message_type, const char *module, const char *message, ...)
{
    va_list args;
    string *module_s = string_init(module);

    string_to_upper(module_s);

    if (logger_get()->level > message_type)
    {
        free(module_s);
        return;
    }
    switch (message_type)
    {
        case MESSAGE_TYPE_DEBUG: { fprintf(logger_get()->f, "### DEBUG   "); break; }
        case MESSAGE_TYPE_WARNING: { fprintf(logger_get()->f, "--- WARNING "); break; }
        case MESSAGE_TYPE_ERROR: { fprintf(logger_get()->f, "!!! ERROR   "); break; }
        case MESSAGE_TYPE_INFO:
        default: { fprintf(logger_get()->f, "    INFO    "); break; }
    }
    fprintf(logger_get()->f, "[%-10s] ", string_get_data(module_s));
    free(module_s);

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