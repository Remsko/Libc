#include "rb_tree_42.h"
#include <stddef.h>

void delete_rb_tree(t_rb_tree **root, t_rb_tree *v)
{
    t_rb_tree *u;
    t_rb_tree *parent;
    bool uv_black;

    u = rb_tree_replace(v);
    parent = v->parent;
    uv_black = ((u == NULL || u->color == BLACK) && (v->color == BLACK));
    if (u == NULL)
    {
        if (v == *root)
            *root = NULL;
        else
        {
            if (uv_black)
                rb_tree_fix_double_black(root, v);
            else
            {
                if (rb_tree_sibling(v) != NULL)
                    rb_tree_sibling(v)->color = RED;
            }

            if (rb_tree_isonleft(v))
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        return;
    }
    if (v->left == NULL || v->right == NULL)
    {
        // possible error
        if (v == *root)
            *root = u;
        else
        {
            if (rb_tree_isonleft(v))
                parent->left = u;
            else
                parent->right = u;
            u->parent = parent;
            if (uv_black)
                rb_tree_fix_double_black(root, u);
            else
                u->color = BLACK;
        }
        return;
    }
    rb_tree_swap_node(u, v);
    delete_rb_tree(root, u);
}
