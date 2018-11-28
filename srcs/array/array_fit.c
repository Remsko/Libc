/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_fit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:32:40 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/28 16:34:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_42.h"

void    array_fit(t_array *arr)
{
    const size_t length;

    length = arr->length * arr->size;
    arr->content = ft_realloc(arr->content, length, length);
}