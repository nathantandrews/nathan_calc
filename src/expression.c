#include "expression.h"
#include "operator.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

ast_node* tree_node_create(void)
{
    ast_node* new_tree_node = (ast_node*) malloc(sizeof(*new_tree_node));
    memset(new_tree_node, 0, sizeof(*new_tree_node));
    return new_tree_node;
}

void tree_node_set_left(ast_node* nd, ast_node* new_left)
{
    assert(nd != NULL);
    nd->left = new_left;
}

void tree_node_set_right(ast_node* nd, ast_node* new_right)
{
    assert(nd != NULL);
    nd->right = new_right;
}

void tree_node_set_type(ast_node* nd, expression_type new_tree_node_type)
{
    assert(nd != NULL);
    nd->type = new_tree_node_type;
}

void tree_node_set_op_value(ast_node* nd, calc_operator new_operator)
{
    assert(nd != NULL);
    nd->value.op = new_operator;
}

void tree_node_set_num_value(ast_node* nd, float new_number)
{
    assert(nd != NULL);
    nd->value.number = new_number;
}

ast_node* tree_node_get_left(ast_node* nd)
{
    assert(nd != NULL);
    return nd->left;
}

ast_node* tree_node_get_right(ast_node* nd)
{
    assert(nd != NULL);
    return nd->right;
}

expression_type tree_node_get_type(ast_node* nd)
{
    assert(nd != NULL);
    return nd->type;
}

calc_operator tree_node_get_op_value(ast_node* nd)
{
    assert(nd != NULL);
    return nd->value.op;
}

float tree_node_get_num_value(ast_node* nd)
{
    assert(nd != NULL);
    return nd->value.number;
}

/*TEST*/
void tree_node_print(ast_node* nd)
{
    assert(nd != NULL);
    if (nd->type == EXPRESSION_TYPE_NUMBER)
    {
        printf("%f", nd->value.number);
        return;
    }
    tree_node_print(nd->left);
    operator_to_str(nd->value.op);
    tree_node_print(nd->right);
}

/*TEST*/
void tree_node_destroy(ast_node* nd)
{
    assert(nd != NULL);
    if (nd->left == NULL && nd->right == NULL)
    {
        free(nd);
        return;
    }
    else if (nd->left != NULL && nd->right == NULL)
    {
        tree_node_destroy(nd->left);
    }
    else if (nd->left == NULL && nd->right != NULL)
    {
        tree_node_destroy(nd->right);
    }
    else
    {
        tree_node_destroy(nd->left);
        tree_node_destroy(nd->right);
    }
}

/*TODO*/
status tree_node_populate_tree(ast_node* nd, char* user_input_str)
{
    return STATUS_SUCCESS;
    /*
    char* iter = user_input_str;
    while (*iter != '\0')
    {
        
        ++iter;
    }
    */
}

/*TODO*/
float tree_node_perform_calculation(ast_node* nd)
{
    return 0.0;
}




