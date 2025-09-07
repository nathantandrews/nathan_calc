#ifndef UI_H
#define UI_H

#define INPUT_MAX_LEN 32

typedef struct input_box
{
    char buf[INPUT_MAX_LEN];
    char last_buf[INPUT_MAX_LEN];
    int len;
} input_box;

input_box *ui_input_box_new(void);

void ui_input_box_set_str(const char text[]);
void ui_input_box_set_float(const float result);

#endif /* UI_H */
