/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:18:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/28 15:04:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void array_append(t_array *arr, void *src)
{
    void *hole;

    array_resize_maybe(arr);
    hole = array_index(arr, arr->length);
    ft_memcpy(hole, src, arr->size);
    arr->length += 1;
}