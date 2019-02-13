/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_fixredred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:11:24 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 14:32:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

void rb_tree_fixredred(t_rb_tree **root, t_rb_tree *node)
{
    t_rb_tree *parent;
    t_rb_tree *grandparent;
    t_rb_tree *uncle;

    if (node == *root)
    {
        node->color = BLACK;
        return ;
    }
    parent = node->parent;
    grandparent = parent->parent;
    uncle = rb_tree_uncle(node);
    if (parent->color != BLACK)
    {
        if (uncle != NULL && uncle->color == RED)
        {
            parent->color = BLACK;
            uncle->color = BLACK;
            grandparent->color = RED;
            rb_tree_fixredred(root, grandparent);
        }
        else
        {
            if (rb_tree_isonleft(parent))
            {
                if (rb_tree_isonleft(node))
                    swap_colors(parent, grandparent);
                else
                {
                    rb_tree_left_rotate(root, parent);
                    swap_colors(node, grandparent);
                }
                rb_tree_right_rotate(root, grandparent);
            }
            else
            {
                if (rb_tree_isonleft(node))
                {
                    rb_tree_right_rotate(root, parent);
                    swap_colors(node, grandparent);
                }
                else
                    swap_colors(parent, grandparent);
                rb_tree_left_rotate(root, grandparent);
            }
        }
    }
}