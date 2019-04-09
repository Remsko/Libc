/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:43:22 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 20:42:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void    *array_index(t_array *arr, size_t index)
{
    if (arr->content == NULL || index >= arr->capacity)
        return (NULL);
    return (arr->content + (index * arr->size));
}