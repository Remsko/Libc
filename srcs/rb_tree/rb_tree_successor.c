/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_successor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:25:19 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 12:26:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_successor(t_rb_tree *node)
{
    t_rb_tree *successor;

    successor = node;
    while (successor->left != NULL)
        successor = successor->left;
    return (successor);
}