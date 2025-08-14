#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "tree.h"

node* node_create(void)
{
    node* new_node = (node*) malloc(sizeof(*new_node));
    memset(new_node, 0, sizeof(*new_node));
    return new_node;
}

void node_set_left(node* nd, node* new_left)
{
    assert(nd != NULL);
    nd->left = new_left;
}

void node_set_right(node* nd, node* new_right)
{
    assert(nd != NULL);
    nd->right = new_right;
}

void node_set_type(node* nd, node_t new_node_type)
{
    assert(nd != NULL);
    nd->type = new_node_type;
}

void node_set_op_value(node* nd, operator_t new_operator)
{
    assert(nd != NULL);
    nd->value.operator = new_operator;
}

void node_set_num_value(node* nd, float new_number)
{
    assert(nd != NULL);
    nd->value.number = new_number;
}

node* node_get_left(node* nd)
{
    assert(nd != NULL);
    return nd->left;
}

node* node_get_right(node* nd)
{
    assert(nd != NULL);
    return nd->right;
}

node_t node_get_type(node* nd)
{
    assert(nd != NULL);
    return nd->type;
}

operator_t node_get_op_value(node* nd)
{
    assert(nd != NULL);
    return nd->value.operator;
}

float node_get_num_value(node* nd)
{
    assert(nd != NULL);
    return nd->value.number;
}

void node_print(node* nd)
{
    assert(nd != NULL);
    if (nd->type == NUMBER)
    {
        printf("%f", nd->value.number);
        return;
    }
    node_print(nd->left);
    printf(nd->value.operator);
    node_print(nd->right);
}

void node_destroy(node* nd)
{
    assert(nd != NULL);
    if (nd->left == NULL && nd->right == NULL)
    {
        return;
    }
    else if (nd->left != NULL && nd->right == NULL)
    {
        node_destroy(nd->left);
    }
    else if (nd->left == NULL && nd->right != NULL)
    {
        node_destroy(nd->right);
    }
    else
    {
        node_destroy(nd->left);
        node_destroy(nd->right);
    }
}

Bool node_populate_tree(node* nd, char* userInputStr)
{
    char* iter = userInputStr;
    while (*iter != '\0')
    {
        
        ++iter;
    }
}




