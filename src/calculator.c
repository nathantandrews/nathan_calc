#include <stdlib.h>
#include <stdio.h>

#include "bool.h"
#include "tree_node.h"
#include "ui.h"

int main()
{
    char* user_input_str = (char*) malloc(sizeof(char) * MAX_INPUT_SIZE); 
    tree_node* tree = tree_node_create();
    float result;
    while (fgets(user_input_str, MAX_INPUT_SIZE, stdin))
    {
        printf("user_input_str: %s", user_input_str);
        tree_status_code_t code = tree_node_populate_tree(tree, user_input_str);
        switch (code)
        {
            case SUCCESS:
            {
                result = tree_node_perform_calculation(tree);
                ui_input_box_set_float(result);
                break;
            }
            case LOGIC_ERROR:
            {
                ui_input_box_set_str("LOGIC ERROR");
                break;
            }
            case SYNTAX_ERROR:
            {
                ui_input_box_set_str("SYNTAX ERROR");
                break;
            }
        }
    }
    free(user_input_str);
    return 0;
}