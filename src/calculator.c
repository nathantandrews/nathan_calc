#include "nta_string.h"
#include "nta_logger.h"
#include "nta_args.h"
#include "scanner.h"
#include "parser.h"
#include "ui.h"
#include "status.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

LOG(calculator)

typedef struct calculator
{
    string *input_s;
    float result_f;
    scanner *sc;
    parser *ps;
} calculator;

static calculator *calculator_new(void)
{
    calculator *c = (calculator*) malloc(sizeof(*c));
    listener l;

    assert(c != NULL);
    memset(c, 0, sizeof(*c));

    c->input_s = string_new();
    string_resize(c->input_s, INPUT_MAX_LEN);
    memset(c->input_s, 0, sizeof(*c->input_s));

    c->sc = scanner_new();
    calculator_log_info("scanner created.\n");

    c->ps = parser_new();
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
    assert(c != NULL);

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
    assert(c != NULL);
    
    while (fgets(c->input_s->data, INPUT_MAX_LEN, stdin))
    {
        /*scanner_scan(c->sc, c->input_s);*/
        /*calculator_log_status(s);*/
        
        
    }
}

int main(int argc, char *argv[])
{
    calculator *calc;
    bool *flags = malloc(sizeof(*flags) * FLAG_COUNT);
    
    args_get_flags(flags, argc, argv);
    logger_set_debug(flags[FLAG_DEBUG]);
    
    calc = calculator_new();
    
    calculator_run(calc);
    
    calculator_free(calc);
    logger_free();
    return 0;
}
