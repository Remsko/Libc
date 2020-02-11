#include "rb_tree_42.h"

static void swap_branch(t_rb_tree *b1, t_rb_tree *b2)
{
    t_rb_tree tmp;

    tmp = *b1;
    *b2 = *b1;
    *b1 = tmp;
}

void rb_tree_swap_node(t_rb_tree *node1, t_rb_tree *node2)
{
    swap_branch(node1->left, node2->left);
    swap_branch(node1->right, node2->right);
    swap_branch(node1->parent, node2->parent);
    swap_colors(node1, node2);
}