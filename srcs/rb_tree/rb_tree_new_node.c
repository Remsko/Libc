/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_new_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 23:10:35 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 23:16:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "rb_tree_42.h"

t_rb_tree *rb_tree_new_node(void *data)
{
    t_rb_tree *node;

    if ((node = (t_rb_tree *)ft_memalloc(sizeof(t_rb_tree))) != NULL)
        node->data = data;
    return (node);
}