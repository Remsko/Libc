/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:37:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 21:53:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline size_t found_zero(const char *str, const char *pchar, const char *pend,  unsigned long word)
{
	const char		*cp;
	unsigned short	index;
	
	while (word < (unsigned long)pend)
	{
		if ((word - MASK01) & (~word & MASK80))
		{
			cp = (const char *)word;
			index = ~0;
			if (cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0')
			{
				pchar = cp + index;
				break ;
			}
		}
		word += MEM_WORD_LEN;
		pchar = pend;
	}
	if (pchar > pend)
		pchar = pend;
	return (pchar - str);
}

size_t				ft_strnlen(const char *str, size_t maxlen)
{
	const char		*pchar;
	const char		*pend;
	unsigned long	word;

	if (maxlen == 0)
		return (0);
	pend = str + maxlen;
	word = (unsigned long)str & ~(MEM_WORD_LEN - 1);
	word += MEM_WORD_LEN;
	pchar = str;
	while (pchar < (const char *)word)
	{
		if (*pchar == '\0')
		{
			if (pchar > pend)
				pchar = pend;
			return (pchar - str);
		}
		++pchar;
	}
	return (found_zero(str, pchar, pend, word));
}
