/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:32:54 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 14:04:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb_tree_42.h"

void rb_tree_insert(t_rb_tree **root, void *data, int (*cmp_f)(void *, void *))
{
    t_rb_tree *new_node;
    t_rb_tree *search;
    int diff;

    if (root == NULL)
        return ;
    new_node = rb_tree_new_node(data);
    if (*root == NULL)
    {
        new_node->color = BLACK;
        *root = new_node;
        return ;
    }
    search = rb_tree_search(*root, data, cmp_f);
    diff = cmp_f(data, search->data);
    if (diff == 0)
    {
        free(new_node);
        return ;
    }
    new_node->parent = search;
    if (diff < 0)
        search->left = new_node;
    else
        search->right = new_node;
    rb_tree_fixredred(root, new_node);
}