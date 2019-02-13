/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_right_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:31:05 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:32:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

void rb_tree_right_rotate(t_rb_tree **root, t_rb_tree *node)
{
    t_rb_tree *nparent;

    nparent = node->left;
    if (node == *root)
        *root = nparent;
    rb_tree_move_down(node , nparent);
    node->left = nparent->right;
    if (nparent->right != NULL)
        nparent->right->parent = node;
    nparent->right = node;
}