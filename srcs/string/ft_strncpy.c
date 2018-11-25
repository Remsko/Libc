/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:02:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 16:48:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

char *ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t size;

	size = ft_strnlen(s2, n);
	if (size != n)
		ft_bzero((void *)(s1 + size), n - size);
	return ((char *)ft_memcpy(s1, s2, size));
}
