#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tree_node.h"
#include "operator.h"

tree_node* tree_node_create(void)
{
    tree_node* new_tree_node = (tree_node*) malloc(sizeof(*new_tree_node));
    memset(new_tree_node, 0, sizeof(*new_tree_node));
    return new_tree_node;
}

void tree_node_set_left(tree_node* nd, tree_node* new_left)
{
    assert(nd != NULL);
    nd->left = new_left;
}

void tree_node_set_right(tree_node* nd, tree_node* new_right)
{
    assert(nd != NULL);
    nd->right = new_right;
}

void tree_node_set_type(tree_node* nd, tree_node_t new_tree_node_type)
{
    assert(nd != NULL);
    nd->type = new_tree_node_type;
}

void tree_node_set_op_value(tree_node* nd, operator_t new_operator)
{
    assert(nd != NULL);
    nd->value.op = new_operator;
}

void tree_node_set_num_value(tree_node* nd, float new_number)
{
    assert(nd != NULL);
    nd->value.number = new_number;
}

tree_node* tree_node_get_left(tree_node* nd)
{
    assert(nd != NULL);
    return nd->left;
}

tree_node* tree_node_get_right(tree_node* nd)
{
    assert(nd != NULL);
    return nd->right;
}

tree_node_t tree_node_get_type(tree_node* nd)
{
    assert(nd != NULL);
    return nd->type;
}

operator_t tree_node_get_op_value(tree_node* nd)
{
    assert(nd != NULL);
    return nd->value.op;
}

float tree_node_get_num_value(tree_node* nd)
{
    assert(nd != NULL);
    return nd->value.number;
}

/*TEST*/
void tree_node_print(tree_node* nd)
{
    assert(nd != NULL);
    if (nd->type == NUMBER)
    {
        printf("%f", nd->value.number);
        return;
    }
    tree_node_print(nd->left);
    operator_print(nd->value.op);
    tree_node_print(nd->right);
}

/*TEST*/
void tree_node_destroy(tree_node* nd)
{
    assert(nd != NULL);
    if (nd->left == NULL && nd->right == NULL)
    {
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
tree_status_code_t tree_node_populate_tree(tree_node* nd, char* user_input_str)
{
    return SUCCESS;
    /*
    char* iter = user_input_str;
    while (*iter != '\0')
    {
        
        ++iter;
    }
    */
}

/*TODO*/
float tree_node_perform_calculation(tree_node* nd)
{
    return 0.0;
}




