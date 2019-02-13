/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 12:09:44 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 12:10:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree_42.h"

void swap_datas(t_rb_tree *node1, t_rb_tree *node2)
{
    void *data;

    data = node1->data;
    node1->data = node2->data;
    node2->data = data;
}