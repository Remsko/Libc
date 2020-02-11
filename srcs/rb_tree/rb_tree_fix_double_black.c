#include "rb_tree_42.h"
#include <stddef.h>

void rb_tree_fix_double_black(t_rb_tree **root, t_rb_tree *x)
{
    t_rb_tree *sibling;
    t_rb_tree *parent;

    if (x == *root)
        return;
    sibling = rb_tree_sibling(x);
    parent = x->parent;
    if (sibling == NULL)
        rb_tree_fix_double_black(root, parent);
    else
    {
        if (sibling->color == RED)
        {
            parent->color = RED;
            sibling->color = BLACK;
            if (rb_tree_isonleft(sibling))
                rb_tree_right_rotate(root, parent);
            else
                rb_tree_left_rotate(root, parent);
            rb_tree_fix_double_black(root, x);
        }
        else
        {
            if (rb_tree_hasredchild(sibling))
            {
                if (sibling->left != NULL && sibling->left->color == RED)
                {
                    if (rb_tree_isonleft(sibling))
                    {
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        rb_tree_right_rotate(root, parent);
                    }
                    else
                    {
                        sibling->left->color = parent->color;
                        rb_tree_right_rotate(root, sibling);
                        rb_tree_left_rotate(root, parent);
                    }
                }
                else
                {
                    if (rb_tree_isonleft(sibling))
                    {
                        sibling->right->color = parent->color;
                        rb_tree_left_rotate(root, sibling);
                        rb_tree_right_rotate(root, parent);
                    }
                    else
                    {
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        rb_tree_left_rotate(root, parent);
                    }
                }
                parent->color = BLACK;
            }
            else
            {
                sibling->color = RED;
                if (parent->color == BLACK)
                    rb_tree_fix_double_black(root, parent);
                else
                    parent->color = BLACK;
            }
        }
    }
}