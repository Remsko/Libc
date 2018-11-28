/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:18:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/28 11:58:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void array_append(t_array *arr, void *src)
{
    if (arr->length == arr->capacity - 1)
    {
        arr->capacity <<= 2;
        arr->content = ft_realloc(arr->content,
                                  arr->capacity * arr->size,
                                  arr->length * arr->size);
    }
    arr->length += 1;
    ft_memcpy(array_index(arr, arr->length), src, arr->size);
}