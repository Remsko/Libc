/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:18:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/21 19:55:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void array_append(t_array *arr, const void *src)
{
    void *hole;

    array_resize_maybe(arr);
    hole = array_index(arr, arr->length);
    if (hole == NULL)
        return ;
    ft_memcpy(hole, src, arr->size);
    arr->length += 1;
}