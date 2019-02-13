/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_isonleft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:56:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 12:57:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rb_tree_42.h"

bool rb_tree_isonleft(t_rb_tree *node)
{
    return (node->parent->left == node);
}