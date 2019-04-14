/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:22:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 20:55:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline char	*found_c_or_zero(unsigned long ul_ptr, unsigned long cccc, unsigned char c)
{
	const unsigned char	*ptr;
	unsigned long		c_ptr;
	unsigned short		index;
	
	while (1)
	{
		c_ptr = ul_ptr ^ cccc;
		if ((c_ptr - MASK01) & (~c_ptr & MASK80)
				|| (ul_ptr - MASK01) & (~ul_ptr & MASK80))
		{
			ptr = (const unsigned char *)ul_ptr;
			index = 0;
			while (index < MEM_WORD_LEN)
			{
				if (ptr[index] == c)
					return (char *)(ptr + index);
				else if (ptr[index] == '\0')
					return (NULL);
				++index;
			}
		}
		ul_ptr += MEM_WORD_LEN;
	}
}

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*ptr;
	unsigned long		ul_ptr;
	unsigned long		cccc;

	ul_ptr = (unsigned long)s & ~(MEM_WORD_LEN - 1);
	ul_ptr += MEM_WORD_LEN;
	ptr = (const unsigned char *)s;
	while (ptr < (const unsigned char *)ul_ptr)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		else if (*ptr == '\0')
			return (NULL);
		++ptr;
	}
	cccc = c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	return (found_c_or_zero(ul_ptr, cccc, (unsigned char)c));
}