/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:00:14 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:39:45 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_42.h"

t_array	*array_create(size_t size)
{
	t_array *arr;

	if ((arr = (t_array *)malloc(sizeof(t_array))) == NULL)
		return (NULL);
	arr->length = 0;
	arr->capacity = MIN_CAPACITY;
	arr->size = size;
	if ((arr->content = malloc(arr->capacity * arr->size)) == NULL)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
