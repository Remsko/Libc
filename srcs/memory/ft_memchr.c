/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:30 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 15:56:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void *ft_memchr(void const *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned long int	ul_ptr;
	unsigned long int	c_ptr;
	unsigned long int	cccc;

	if (n == 0)
		return (0);
	ul_ptr = (unsigned long int)s & OVER_HEIGHT;
	ul_ptr += MEM_WORD_LEN;
	ptr = (const unsigned char *)s;
	while (ptr < (const unsigned char *)ul_ptr && n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		++ptr;
		--n;
	}
	cccc = (unsigned char)c;
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
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		++ptr;
		--n;
	}
	return (NULL);
}
