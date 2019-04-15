/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:22:38 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/15 13:39:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline char	*search_loop(unsigned long word, unsigned long cccc,
						unsigned char c)
{
	const unsigned char	*pchar;
	unsigned long		p;
	unsigned short		index;

	while (1)
	{
		p = word ^ cccc;
		if ((p - MASK01) & (~p & MASK80) || (word - MASK01) & (~word & MASK80))
		{
			pchar = (const unsigned char *)word;
			index = 0;
			while (index < MEM_WORD_LEN)
			{
				if (pchar[index] == c)
					return (char *)(pchar + index);
				else if (pchar[index] == '\0')
					return (NULL);
				++index;
			}
		}
		word += MEM_WORD_LEN;
	}
}

char				*ft_strchr(const char *s, int c)
{
	const unsigned char	*pchar;
	unsigned long		word;
	unsigned long		cccc;

	word = (unsigned long)s & ~(MEM_WORD_LEN - 1);
	word += MEM_WORD_LEN;
	pchar = (const unsigned char *)s;
	while (pchar < (const unsigned char *)word)
	{
		if (*pchar == (unsigned char)c)
			return ((char *)pchar);
		else if (*pchar == '\0')
			return (NULL);
		++pchar;
	}
	cccc = c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	return (search_loop(word, cccc, (unsigned char)c));
}
