/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:00:14 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/28 11:10:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_42.h"

t_array *array_create(size_t size)
{
    t_array *arr;

    if ((arr = (t_array *)malloc(sizeof(t_array))) == NULL)
        return (NULL);
    arr->length = 0;
    arr->capacity = MIN_CAPACITY;
    arr->size = size;
    arr->content = malloc(arr->capacity * arr->size);
    return (arr);
}