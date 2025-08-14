#include <stdlib.h>
#include <stdio.h>

#include "bool.h"
#include "tree.h"
#include "ui.h"

int main()
{
    char* user_input_str = (char*) malloc(sizeof(char) * MAX_INPUT_SIZE);
    /* 
    node* tree = node_create();
    float result; 
    */
    while (fgets(user_input_str, MAX_INPUT_SIZE, stdin))
    {
        printf("%s\n", user_input_str);
        /*
        if (!node_populate_tree(tree, user_input_str))
        {
            ui_set_screen_text("ERROR");
        }
        else
        {
            result = node_perform_calculation();
            ui_display_result(result);
        }
        
        ui_display_calculation();        
        */
        break;
    }
    free(user_input_str);
    return 0;
}