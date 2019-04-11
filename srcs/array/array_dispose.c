/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dispose.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:48:13 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:45:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array_42.h"

void	array_dispose(t_array *arr, void ft_free(void *, size_t))
{
	if (ft_free != NULL)
		ft_free((void *)arr->content, arr->length);
	free(arr);
}
