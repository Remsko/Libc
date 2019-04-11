/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:18:46 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:39:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void	array_append(t_array *arr, const void *src)
{
	void *rear;

	array_resize_maybe(arr);
	rear = array_index(arr, arr->length);
	if (rear == NULL)
		return ;
	ft_memcpy(rear, src, arr->size);
	arr->length += 1;
}
