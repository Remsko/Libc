/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_fit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:32:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:44:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"
#include "memory_42.h"

void	array_fit(t_array *arr)
{
	const size_t total_length = arr->length * arr->size;

	arr->content = ft_realloc(arr->content, total_length, total_length);
	arr->capacity = arr->length;
}
