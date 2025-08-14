#ifndef UI_H
#define UI_H

#define MAX_INPUT_SIZE 32

typedef struct input_box
{
    char input_box_str[MAX_INPUT_SIZE];
    char last_input_box_str[MAX_INPUT_SIZE];
    int len;
} input_box;

input_box* input_box_create(void);

void ui_set_screen_text(char* text);
void ui_display_result(float result);

#endif