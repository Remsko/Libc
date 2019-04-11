/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:22:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:22:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

char	*ft_strchr(const char *s, int c_in)
{
	const unsigned char	*ptr;
	unsigned long int	ul_ptr;
	unsigned long int	c_ptr;
	unsigned long int	cccc;
	unsigned char		c;

	c = (unsigned char)c_in;
	ul_ptr = (unsigned long int)s & OVER_HEIGHT;
	ul_ptr += MEM_WORD_LEN;
	ptr = (const unsigned char *)s;
	while (ptr < (const unsigned char *)ul_ptr)
	{
		if (*ptr == c)
			return ((char *)ptr);
		else if (*ptr == '\0')
			return (NULL);
		++ptr;
	}
	cccc = c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	while (1)
	{
		c_ptr = ul_ptr ^ cccc;
		if ((c_ptr - MASK01) & (~c_ptr & MASK80)
				|| (ul_ptr - MASK01) & (~ul_ptr & MASK80))
		{
			ptr = (const unsigned char *)ul_ptr;
			if (ptr[0] == c)
				return (char *)(ptr);
			else if (ptr[0] == '\0')
				return (NULL);
			if (ptr[1] == c)
				return (char *)(ptr + 1);
			else if (ptr[1] == '\0')
				return (NULL);
			if (ptr[2] == c)
				return (char *)(ptr + 2);
			else if (ptr[2] == '\0')
				return (NULL);
			if (ptr[3] == c)
				return (char *)(ptr + 3);
			else if (ptr[3] == '\0')
				return (NULL);
			if (ptr[4] == c)
				return (char *)(ptr + 4);
			else if (ptr[4] == '\0')
				return (NULL);
			if (ptr[5] == c)
				return (char *)(ptr + 5);
			else if (ptr[5] == '\0')
				return (NULL);
			if (ptr[6] == c)
				return (char *)(ptr + 6);
			else if (ptr[6] == '\0')
				return (NULL);
			if (ptr[7] == c)
				return ((char *)ptr + 7);
			else if (ptr[7] == '\0')
				return (NULL);
		}
		ul_ptr += MEM_WORD_LEN;
	}
	return (NULL);
}
