#ifndef UI_H
#define UI_H

#define MAX_INPUT_SIZE 32

typedef struct input_box
{
    char buf[MAX_INPUT_SIZE];
    char last_buf[MAX_INPUT_SIZE];
    int len;
} input_box;

input_box* ui_input_box_create(void);

void ui_input_box_set_str(const char text[]);
void ui_input_box_set_float(float result);

#endif