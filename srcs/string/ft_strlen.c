/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:37:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 21:53:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline size_t	found_zero(const char *str, const char *pchar,
							unsigned long word)
{
	while (1)
	{
		if ((word - MASK01) & (~word & MASK80))
		{
			pchar = (const char *)word;
			if (pchar[0] == '\0')
				return (pchar - str);
			if (pchar[1] == '\0')
				return (pchar - str + 1);
			if (pchar[2] == '\0')
				return (pchar - str + 2);
			if (pchar[3] == '\0')
				return (pchar - str + 3);
			if (pchar[4] == '\0')
				return (pchar - str + 4);
			if (pchar[5] == '\0')
				return (pchar - str + 5);
			if (pchar[6] == '\0')
				return (pchar - str + 6);
			if (pchar[7] == '\0')
				return (pchar - str + 7);
		}
		word += MEM_WORD_LEN;
	}
	return (0);
}

size_t					ft_strlen(const char *str)
{
	const char		*pchar;
	unsigned long	word;

	word = (unsigned long)str & ~(MEM_WORD_LEN - 1);
	word += MEM_WORD_LEN;
	pchar = str;
	while (pchar < (const char *)word)
	{
		if (*pchar == '\0')
			return (pchar - str);
		++pchar;
	}
	return (found_zero(str, pchar, word));
}
