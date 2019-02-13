/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_move_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:06:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:09:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

void    rb_tree_move_down(t_rb_tree *node, t_rb_tree *nparent)
{
    if (node->parent != NULL)
    {
        if (rb_tree_isonleft(node))
            node->parent->left = nparent;
        else
            node->parent->right = nparent;
    }
    nparent->parent = node->parent;
    node->parent = nparent;
}