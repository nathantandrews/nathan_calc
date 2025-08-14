#ifndef TREE_H
#define TREE_H

#include "operator.h"

#define MAX_NUMBER_TOKENS 10
#define MAX_OPERATOR_TOKENS 5

typedef enum tree_status_code_t
{
    SUCCESS = 0,
    LOGIC_ERROR = 1,
    SYNTAX_ERROR = 2
} tree_status_code_t;

typedef enum tree_node_t
{
    OPERATOR = 0,
    NUMBER = 1
} tree_node_t;

typedef struct tree_node
{
    struct tree_node* left;
    struct tree_node* right;
    
    tree_node_t type;
    union value
    {
        operator_t op;
        float number;
    } value;
    
} tree_node;

/*Binary Tree Node Core Functions*/

/*create a tree_node with all values set to NULL*/
tree_node* tree_node_create(void);

void tree_node_set_left(tree_node* nd, tree_node* new_left);
void tree_node_set_right(tree_node* nd, tree_node* new_right);
void tree_node_set_type(tree_node* nd, tree_node_t new_node_type);
void tree_node_set_op_value(tree_node* nd, operator_t new_operator_type);
void tree_node_set_num_value(tree_node* nd, float new_number);

tree_node* tree_node_get_left(tree_node* nd);
tree_node* tree_node_get_right(tree_node* nd);
tree_node_t tree_node_get_type(tree_node* nd);
operator_t tree_node_get_op_value(tree_node* nd);
float tree_node_get_num_value(tree_node* nd);

/*print a tree_node and print its children recursively*/
void tree_node_print(tree_node* nd);

/*destroy a tree_node and recursively destroy it's children*/
void tree_node_destroy(tree_node* nd);

/*Input Processing*/

tree_status_code_t tree_node_populate_tree(tree_node* nd, char* userInputStr);

float tree_node_perform_calculation(tree_node* nd);

#endif