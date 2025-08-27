#include "scanner.h"
#include "parser.h"
#include "ui.h"
#include "status.h"
#include "logger.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

MODULE_DEBUG(calculator)

typedef struct calculator
{
    char *input_s;
    float result_f;
    logger *l;
    scanner *sc;
    parser *ps;
} calculator;

static calculator *calculator_create(void);
static status calculator_free(calculator *c);
static void calculator_run(calculator *c);

static calculator *calculator_create(void)
{
    calculator *c = (calculator*) malloc(sizeof(*c));
    listener l;

    if (c == NULL)
    {
        calculator_log_error("calculator not allocated, not enough memory.\n");
        return NULL;
    }
    memset(c, 0, sizeof(*c));

    c->input_s = (char*) malloc(sizeof(*c->input_s) * INPUT_MAX_LEN);
    if (c->input_s == NULL)
    {
        calculator_log_error("input string not allocated, not enough memory.\n");
        return NULL;
    }
    memset(c->input_s, 0, sizeof(*c->input_s));

    c->sc = scanner_create();
    calculator_log_info("scanner created.\n");

    c->ps = parser_create();
    calculator_log_info("parser created.\n");

    l.cb_fn = &parser_token_event;
    l.context = c->ps;
    scanner_set_listener(c->sc, &l);
    calculator_log_info("scanner listener set.\n");

    

    calculator_log_info("calculator created.\n");
    return c;
}

static status calculator_free(calculator *c)
{
    free(c->input_s);
    calculator_log_info("input string freed.\n");
    scanner_free(c->sc);
    calculator_log_info("scanner freed.\n");
    parser_free(c->ps);
    calculator_log_info("parser freed.\n");
    


    free(c);
    calculator_log_info("calculator freed.\n");
    return STATUS_SUCCESS;
}

static void calculator_run(calculator *c)
{
    while (fgets(c->input_s, INPUT_MAX_LEN, stdin))
    {
        scanner_scan(c->sc, c->input_s);
        /*calculator_log_status(s);*/

        
    }
    calculator_free(c);
}

int main(int argc, char *argv[])
{
    calculator *calc = calculator_create();
    
    calculator_run(calc);
    return 0;
}
