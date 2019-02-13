/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_left_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:24:15 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:30:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

void rb_tree_left_rotate(t_rb_tree **root, t_rb_tree *node)
{
    t_rb_tree *nparent;

    nparent = node->right;
    if (node == *root)
        *root = nparent;
    rb_tree_move_down(node , nparent);
    node->right = nparent->left;
    if (nparent->left != NULL)
        nparent->left->parent = node;
    nparent->left = node;
}