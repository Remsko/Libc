/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:37:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/21 19:59:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void    array_insert(t_array *arr, void *p, size_t index)
{
    void *hole;

    array_resize_maybe(arr);
    hole = array_index(arr, index);
    if (hole == NULL)
        return ;
    ft_memmove(hole + 1, hole, (arr->length - index) * arr->size);
    ft_memcpy(hole, p, arr->size);
    arr->length += 1;
}