#ifndef TREE_H
#define TREE_H

#include "bool.h"

#define MAX_NUMBER_TOKENS 10
#define MAX_OPERATOR_TOKENS 5

typedef enum operator_t
{
    ADD = 0,
    SUB = 1,
    MUL = 2,
    DIV = 3
} operator_t;

typedef enum node_t
{
    OPERATOR = 0,
    NUMBER = 1
} node_t;

typedef struct node
{
    struct node* left;
    struct node* right;
    
    node_t type;
    union
    {
        operator_t operator;
        float number;
    } value;
    
} node;

/* Binary Tree Node Core Functions */

/* create a node with all values set to NULL*/
node* node_create(void);

void node_set_left(node* nd, node* new_left);
void node_set_right(node* nd, node* new_right);
void node_set_type(node* nd, node_t new_node_type);
void node_set_op_value(node* nd, operator_t new_operator_type);
void node_set_num_value(node* nd, float new_number);

node* node_get_left(node* nd);
node* node_get_right(node* nd);
node_t node_get_type(node* nd);
operator_t node_get_op_value(node* nd);
float node_get_num_value(node* nd);

/* print a node and print its children recursively */
void node_print(node* nd);

/* destroy a node and recursively destroy it's children */
void node_destroy(node* nd);

/* Input Processing */

/* populate a tree using a string / character array */
Bool node_populate_tree(node* nd, char* userInputStr);

#endif