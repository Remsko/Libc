/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_resize_maybe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:45:14 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:44:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void	array_resize_maybe(t_array *arr)
{
	if (arr->length == arr->capacity - 1)
	{
		arr->capacity <<= 1;
		arr->content = ft_realloc(arr->content, arr->capacity * arr->size,
			arr->length * arr->size);
	}
}
