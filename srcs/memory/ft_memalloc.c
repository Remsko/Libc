/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:55:40 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/27 14:58:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void	*ft_memalloc(size_t size)
{
	void *ret;

	if ((ret = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
