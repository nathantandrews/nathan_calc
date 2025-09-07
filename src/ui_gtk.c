#include "ui.h"
#include "nta_logger.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LOG(ui_gtk)

input_box* ui_input_box_new(void)
{
    input_box* new_input_box = (input_box*) malloc(sizeof(*new_input_box));
    memset(new_input_box, 0, sizeof(*new_input_box));
    return new_input_box;
}

void ui_input_box_set_str(const char text[])
{
    ui_gtk_log_info("setting screen text to %s\n", text);
}

void ui_input_box_set_float(const float result)
{
    ui_gtk_log_info("printing result: %f\n", result);
}
