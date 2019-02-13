/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:42:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 12:09:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree_42.h"

void swap_colors(t_rb_tree *node1, t_rb_tree *node2)
{
    t_rb_color color;

    color = node1->color;
    node1->color = node2->color;
    node2->color = color;
}
