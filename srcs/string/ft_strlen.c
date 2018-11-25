/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:37:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 16:48:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

static inline size_t found_zero(const char *str, const char *ptr,  unsigned long int ul_ptr)
{
	while (1)
	{
		if ((ul_ptr - MASK01) & (~ul_ptr & MASK80))
		{
			ptr = (const char *)ul_ptr;
			if (ptr[0] == '\0')
				return (ptr - str);
			if (ptr[1] == '\0')
				return (ptr - str + 1);
			if (ptr[2] == '\0')
				return (ptr - str + 2);
			if (ptr[3] == '\0')
				return (ptr - str + 3);
			if (ptr[4] == '\0')
				return (ptr - str + 4);
			if (ptr[5] == '\0')
				return (ptr - str + 5);
			if (ptr[6] == '\0')
				return (ptr - str + 6);
			if (ptr[7] == '\0')
				return (ptr - str + 7);
		}
		ul_ptr += MEM_WORD_LEN;
	}
	return (0);
}

size_t  ft_strlen(const char *str)
{
	const char		*ptr;
	unsigned long int	ul_ptr;

	ul_ptr = (unsigned long int)str & OVER_HEIGHT;
	ul_ptr += MEM_WORD_LEN;
	if ((ul_ptr - MASK01) & (~ul_ptr & MASK80))
	{
		ptr = str;
		while (ptr < (const char *)ul_ptr)
		{
			if (*ptr == '\0')
				return (ptr - str);
			++ptr;
		}
	}
	return (found_zero(str, ptr, ul_ptr));
}
