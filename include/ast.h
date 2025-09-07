#ifndef AST_H
#define AST_H

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

ast_node *ast_node_new(void);
void ast_node_free(ast_node *nd);

void ast_node_set_left(ast_node *nd, const ast_node *new_left);
void ast_node_set_right(ast_node *nd, const ast_node *new_right);
void ast_node_set_type(ast_node *nd, expression_type new_node_type);
void ast_node_set_op_value(ast_node *nd, calc_operator new_operator_type);
void ast_node_set_num_value(ast_node *nd, float new_number);

ast_node *ast_node_get_left(const ast_node *nd);
ast_node *ast_node_get_right(const ast_node *nd);

expression_type ast_node_get_type(const ast_node *nd);
calc_operator ast_node_get_op_value(const ast_node *nd);
float ast_node_get_num_value(const ast_node *nd);

#endif /* AST_H */
