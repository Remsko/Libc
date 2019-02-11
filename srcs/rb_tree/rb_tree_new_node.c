/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 23:10:35 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 23:38:14 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_new_node(void *data)
{
    t_rb_tree *node;

    if ((node = (t_rb_tree *)malloc(sizeof(t_rb_tree))) != NULL)
    {
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        node->data = data;
        node->color = RED;
    }
    return (node);
}