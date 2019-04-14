/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:37:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 21:28:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline size_t found_zero(const char *str, const char *ptr, const char *end_ptr,  unsigned long ul_ptr)
{
	const char		*cp;
	unsigned short	index;
	
	while (ul_ptr < (unsigned long)end_ptr)
	{
		if ((ul_ptr - MASK01) & (~ul_ptr & MASK80))
		{
			cp = (const char *)ul_ptr;
			index = ~0;
			if (cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0' || cp[++index] == '\0'
				|| cp[++index] == '\0')
			{
				ptr = cp + index;
				break ;
			}
		}
		ul_ptr += MEM_WORD_LEN;
		ptr = end_ptr;
	}
	if (ptr > end_ptr)
		ptr = end_ptr;
	return (ptr - str);
}

size_t  ft_strnlen(const char *str, size_t maxlen)
{
	const char		*ptr;
	const char		*end_ptr;
	unsigned long	ul_ptr;

	if (maxlen == 0)
		return (0);
	end_ptr = str + maxlen;
	ul_ptr = (unsigned long)str & ~(MEM_WORD_LEN - 1);
	ul_ptr += MEM_WORD_LEN;
	ptr = str;
	while (ptr < (const char *)ul_ptr)
	{
		if (*ptr == '\0')
		{
			if (ptr > end_ptr)
				ptr = end_ptr;
			return (ptr - str);
		}
		++ptr;
	}
	return (found_zero(str, ptr, end_ptr, ul_ptr));
}
