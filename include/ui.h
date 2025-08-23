#ifndef UI_H
#define UI_H

#include "input_constants.h"

typedef struct input_box
{
    char buf[INPUT_MAX_LEN];
    char last_buf[INPUT_MAX_LEN];
    int len;
} input_box;

input_box *ui_input_box_create(void);

void ui_input_box_set_str(const char text[]);
void ui_input_box_set_float(const float result);

#endif