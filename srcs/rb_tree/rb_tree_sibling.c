/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_sibling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:01:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:03:17 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_sibling(t_rb_tree *node)
{
    if (node->parent == NULL) 
        return (NULL); 
    if (rb_tree_isonleft(node)) 
        return (node->parent->right);
    else
        return (node->parent->left); 
}