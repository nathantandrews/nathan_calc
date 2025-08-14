#include <stdio.h>

#include "ui.h"

input_box* input_box_create(void)
{
    input_box* new_input_box = (input_box*) malloc(sizeof(*new_input_box));
    memset(new_input_box, 0, sizeof(*new_input_box));
    return new_input_box;
}

void ui_set_screen_text(char* text)
{
    printf("setting screen text to %s\n", &text);
}

void ui_display_result(float result)
{
    printf("printing result: %f\n", result);
}