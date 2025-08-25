#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "operator.h"
#include "status.h"

typedef enum expression_type
{
    EXPRESSION_TYPE_NUMBER,
    EXPRESSION_TYPE_UNARY_OPERATOR,
    EXPRESSION_TYPE_BINARY_OPERATOR,
    EXPRESSION_TYPE_FUNCTION,
    EXPRESSION_TYPE_COUNT
} expression_type;

typedef struct ast_node
{
    struct ast_node *left;
    struct ast_node *right;
    
    expression_type type;
    union value
    {
        calc_operator op;
        float number;
    } value;
    
} ast_node;

/*Binary Tree Node Core Functions*/

/*create a ast_node with all values set to NULL*/
ast_node *tree_node_create(void);

void tree_node_set_left(ast_node *nd, ast_node *new_left);
void tree_node_set_right(ast_node *nd, ast_node *new_right);
void tree_node_set_type(ast_node *nd, expression_type new_node_type);
void tree_node_set_op_value(ast_node *nd, calc_operator new_operator_type);
void tree_node_set_num_value(ast_node *nd, float new_number);

ast_node * tree_node_get_left(ast_node *nd);
ast_node * tree_node_get_right(ast_node *nd);
expression_type tree_node_get_type(ast_node *nd);
calc_operator tree_node_get_op_value(ast_node *nd);
float tree_node_get_num_value(ast_node *nd);

/*print a ast_node and print its children recursively*/
void tree_node_print(ast_node *nd);

/*destroy a ast_node and recursively destroy it's children*/
void tree_node_destroy(ast_node *nd);

/*Input Processing*/

status tree_node_populate_tree(ast_node *nd, char *userInputStr);

float tree_node_perform_calculation(ast_node *nd);

#endif