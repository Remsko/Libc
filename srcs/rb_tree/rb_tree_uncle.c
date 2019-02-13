/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_uncle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:54:20 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:00:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_uncle(t_rb_tree *node)
{
    t_rb_tree *uncle;
    
    if (node->parent == NULL || node->parent->parent == NULL)
        return (NULL);
    if (rb_tree_isonleft(node->parent))
        return (node->parent->parent->right);
    else
        return (node->parent->parent->left);
}