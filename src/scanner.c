#include "scanner.h"
#include "token.h"
#include "bool.h"
#include "operator.h"
#include "input_constants.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

scanner *scanner_create(void)
{
    scanner *new_scanner = (scanner*) malloc(sizeof(*new_scanner));
    memset(new_scanner, 0, sizeof(*new_scanner));
    scanner_set_state(new_scanner, TOKEN_TYPE_DEFAULT);
    return new_scanner;
}
void scanner_destroy(scanner *sc)
{
    assert(sc != NULL);
    free(sc);
}

void scanner_set_state(scanner *sc, const token_type state)
{
    assert(sc != NULL);
    printf("scanner_set_state: %s -> %s\n", token_type_to_str(sc->state), token_type_to_str(state));
    sc->state = state;
}
void scanner_set_listener(scanner *sc, const listener *l)
{
    assert(sc != NULL);
    printf("scanner_set_listener\n");
    sc->l = *l;
}

static status scanner_p_accumulate_token(scanner *sc)
{
    if (sc->token_buf.wr < TOKEN_MAX_LEN - 1)
    {
        sc->token_buf.data[sc->token_buf.wr] = *sc->token_buf.rd;
        ++sc->token_buf.wr;
        sc->token_buf.data[sc->token_buf.wr] = '\0';
    }
    else
    {
        return STATUS_TOKEN_MAX_LEN_ERROR;
    }
    return STATUS_SUCCESS;
}

static status scanner_p_generate_token(scanner *sc)
{
    token_init(&sc->t, sc->state, sc->token_buf.data);
    sc->token_buf.wr = 0;
    scanner_p_accumulate_token(sc);
    sc->l.cb_fn(sc->l.context, &sc->t);
    return STATUS_SUCCESS;
}

status scanner_scan(scanner *sc, const char *input)
{
    assert(sc != NULL);
    assert(input != NULL);
    memset(sc->token_buf.data, 0, TOKEN_MAX_LEN);
    sc->token_buf.rd = input;
    sc->token_buf.wr = 0;

    printf("scanner_scan\n");
    printf("%s\n", input);

    while (*sc->token_buf.rd != '\0')
    {
        char c = *sc->token_buf.rd;
        
        if (isspace(c))
        {
            ++sc->token_buf.rd;
            continue;
        }
        else if (iscntrl(c) || strchr("!@$#?:;\\\'\"`[]{}", c))
        {
            return STATUS_INVALID_CHARACTER_ERROR;
        }


        printf("*rd: \"%c\" wr: %d, data: \"%s\"\n", c, sc->token_buf.wr, sc->token_buf.data);

        switch (sc->state)
        {
            case TOKEN_TYPE_DEFAULT:
            {
                printf("scanner_state = DEFAULT\n");
                if (isdigit(c))
                {
                    scanner_p_accumulate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_NUMBER);
                }
                else if (is_operator(c))
                {
                    scanner_p_accumulate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_OPERATOR);
                }
                else if (isalpha(c))
                {
                    scanner_p_accumulate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_KEYWORD);
                }
                break;
            }
            case TOKEN_TYPE_NUMBER:
            {
                printf("scanner_state = NUMBER\n");
                if (isdigit(c))
                {
                    scanner_p_accumulate_token(sc);
                }
                else if (is_operator(c))
                {
                    scanner_p_generate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_OPERATOR);
                }
                else if (isalpha(c))
                {
                    scanner_p_generate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_KEYWORD);
                }
                break;
            }
            case TOKEN_TYPE_OPERATOR:
            {
                printf("scanner_state = OPERATOR\n");
                scanner_p_generate_token(sc);
                if (isdigit(c))
                {
                    scanner_set_state(sc, TOKEN_TYPE_NUMBER);
                }
                else if (is_operator(c))
                {
                    scanner_set_state(sc, TOKEN_TYPE_OPERATOR);
                }
                else if (isalpha(c))
                {
                    scanner_set_state(sc, TOKEN_TYPE_KEYWORD);
                }
                break;
            }
            case TOKEN_TYPE_KEYWORD:
            {
                printf("scanner_state = KEYWORD\n");
                if (isalnum(c))
                {
                    scanner_p_accumulate_token(sc);
                }
                else if (is_operator(c))
                {
                    scanner_p_generate_token(sc);
                    scanner_set_state(sc, TOKEN_TYPE_OPERATOR);
                }
                break;
            }
            default:
            {
                printf("ERROR: INVALID STATE\n");
                break;
            }
        }

        ++sc->token_buf.rd;
    }

    scanner_p_generate_token(sc);

    scanner_set_state(sc, TOKEN_TYPE_DEFAULT);
    return STATUS_SUCCESS;
}