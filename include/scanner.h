#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include "status.h"
#include "logger.h"

typedef void (*listener_cb)(void *context, const token *t);

typedef struct listener
{
    listener_cb cb_fn;
    void *context;
} listener;

typedef struct scanner
{
    token_type state;
    listener l;
    token t;
    struct
    {
        const char *rd;
        int wr;
        char data[TOKEN_MAX_LEN];
    } token_buf;
} scanner;

scanner *scanner_create(void);
void scanner_free(scanner *sc);

void scanner_set_state(scanner *sc, const token_type state);
void scanner_set_listener(scanner *sc, const listener *l);

status scanner_scan(scanner *sc, const char *input);

#endif
