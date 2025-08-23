#include "scanner.h"
#include "parser.h"
#include "ui.h"
#include "input_constants.h"
#include "status.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct calculator
{
    char *input_s;
    float result_f;
    scanner *sc;
    parser *ps;
} calculator;

static calculator *calculator_create();
static status calculator_destroy(calculator *c);
static void calculator_run(calculator *c);

static calculator *calculator_create()
{
    calculator *c = (calculator*) malloc(sizeof(*c));
    listener l;
    c->input_s = (char*) malloc(sizeof(*c->input_s) * INPUT_MAX_LEN);
    assert(c->input_s);
    c->sc = scanner_create();
    c->ps = parser_create();
    l.cb_fn = &parser_token_event;
    l.context = c->ps;
    scanner_set_listener(c->sc, &l);
    return c;
}

static status calculator_destroy(calculator *c)
{
    free(c->input_s);
    scanner_destroy(c->sc);
    parser_destroy(c->ps);
    
    free(c);
    return STATUS_SUCCESS;
}

static void calculator_run(calculator *c)
{
    status scanner_code;
    while (fgets(c->input_s, INPUT_MAX_LEN, stdin))
    {
        scanner_code = scanner_scan(c->sc, c->input_s);
        status_handle_code(scanner_code);
    }
    calculator_destroy(c);
}

int main()
{
    calculator *calc = calculator_create();
    calculator_run(calc);
    return 0;
}