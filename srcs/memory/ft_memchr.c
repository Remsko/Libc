/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/15 14:01:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

inline static void	*align_chr(const unsigned char **ps, unsigned char c,
						size_t *n)
{
	while (*n > 0 && (size_t)(*ps) % MEM_WORD_LEN > 0)
	{
		if ((*ps)[0] == c)
			return ((void *)(*ps));
		*ps += 1;
		*n -= 1;
	}
	return (NULL);
}

inline static void	word_chr(const unsigned long **ps, unsigned long cccc,
						size_t *n)
{
	unsigned long	cp;

	while (*n > MEM_WORD_LEN)
	{
		cp = (*ps[0]) ^ cccc;
		if ((cp - MASK01) & (~cp & MASK80))
			break ;
		*ps += 1;
		*n -= MEM_WORD_LEN;
	}
}

inline static void	*byte_chr(const unsigned char **ps, unsigned char c,
						size_t *n)
{
	while (*n > 0)
	{
		if ((*ps)[0] == c)
			return ((void *)(*ps));
		*ps += 1;
		*n -= 1;
	}
	return (NULL);
}

void				*ft_memchr(void const *s, int c, size_t n)
{
	void			*p;
	unsigned long	cccc;

	if (n >= MEM_WORD_LEN)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= cccc << 32;
		if ((p = align_chr((const unsigned char **)&s, (unsigned char)c, &n)))
			return (p);
		word_chr((const unsigned long **)&s, cccc, &n);
	}
	if ((p = byte_chr((const unsigned char **)&s, (unsigned char)c, &n)))
		return (p);
	return (NULL);
}
