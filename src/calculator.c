#include <stdlib.h>
#include <stdio.h>

#include "bool.h"
#include "tree.h"
#include "ui.h"

int main()
{
    char* userInputStr = (char*) malloc(sizeof(char) * MAX_INPUT_SIZE);
    node* tree = node_create();
    float result;
    while (fgets(userInputStr, MAX_INPUT_SIZE, stdin))
    {
        if (!node_populate_tree(tree, userInputStr))
        {
            ui_set_screen_text("ERROR");
        }
        else
        {
            result = node_perform_calculation();
            ui_display_result(result);
        }
        
        ui_display_calculation();
        break;
    }
    free(userInputStr);
    return 0;
}