/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:27:15 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 12:29:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_replace(t_rb_tree *node)
{
    if (node->left != NULL && node->right != NULL)
        return (rb_tree_successor(node));
    if (node->left == NULL && node->right == NULL)
        return (NULL);
    if (node->left != NULL)
        return (node->left);
    else
        return (node->right);
}