/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:30 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/27 14:19:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void *ft_memchr(void const *s, int c_in, size_t n)
{
	const unsigned char *ptr;
	unsigned long int   ul_ptr;
	unsigned long int   c_ptr;
	unsigned long int   cccc;
	unsigned char       c;

	if (n == 0)
		return (0);
	c = (unsigned char)c_in;
	ptr = (const unsigned char *)s;
	while (n > 0 && (size_t)ptr & OVER_HEIGHT)
	{
		if (*ptr == c)
			return ((void *)ptr);
		--n;
		++ptr;
	}
	ul_ptr = (unsigned long int)ptr;
	cccc = c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	while (n >= MEM_WORD_LEN)
	{
		c_ptr = ul_ptr ^ cccc;
		if ((c_ptr - MASK01) & (~c_ptr & MASK80))
			break ;
		ul_ptr += MEM_WORD_LEN;
		n -= MEM_WORD_LEN;
	}
	ptr = (const unsigned char *)ul_ptr;
	while (n > 0)
	{
		if (*ptr == c)
			return ((void *)ptr);
		--n;
		++ptr;
	}
	return (NULL);
}
