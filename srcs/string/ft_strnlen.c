/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:37:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:25:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline size_t found_zero(const char *str, const char *ptr, const char *end_ptr,  unsigned long int ul_ptr)
{
	const char *cp;

	while (ul_ptr < (unsigned long int)end_ptr)
	{
		if ((ul_ptr - MASK01) & (~ul_ptr & MASK80))
		{
			cp = (const char *)ul_ptr;
			ptr = cp;
			if (cp[0] == '\0')
				break ;
			ptr = cp + 1;
			if (cp[1] == '\0')
				break ;
			ptr = cp + 2;
			if (cp[2] == '\0')
				break ;
			ptr = cp + 3;
			if (cp[3] == '\0')
				break ;
			ptr = cp + 4;
			if (cp[4] == '\0')
				break ;
			ptr = cp + 5;
			if (cp[5] == '\0')
				break ;
			ptr = cp + 6;
			if (cp[6] == '\0')
				break ;
			ptr = cp + 7;
			if (cp[7] == '\0')
				break ;
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
	unsigned long int	ul_ptr;

	if (maxlen == 0)
		return (0);
	end_ptr = str + maxlen;
	ul_ptr = (unsigned long int)str & OVER_HEIGHT;
	ul_ptr += MEM_WORD_LEN;
	if ((ul_ptr - MASK01) & (~ul_ptr & MASK80))
	{
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
	}
	return (found_zero(str, ptr, end_ptr, ul_ptr));
}
