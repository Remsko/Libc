/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:30 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 17:08:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

inline static void	*align_word(const unsigned char **ps, unsigned char c, size_t *n)
{
	while (*n > 0 && (size_t)(*ps) % MEM_WORD_LEN)
	{
		if ((*ps)[0] == c)
			return ((void *)(*ps));
		*ps += 1;
		*n -= 1;
	}
	return (NULL);
}

inline static void	word_search(const unsigned long **ps, unsigned long cccc, size_t *n)
{
	unsigned long	c;
	
	while (*n >= MEM_WORD_LEN)
	{
		c = (**ps) ^ cccc;
		if ((c - MASK01) & (~c & MASK80))
			break ;
		*ps += 1;
		*n -= MEM_WORD_LEN;
	}
}

inline static void	*byte_search(const unsigned char **ps, unsigned char c, size_t *n)
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
	void			*ret;
	unsigned long	cccc;
	
	cccc = (unsigned char)c;
	cccc |= cccc << 8;
	cccc |= cccc << 16;
	cccc |= cccc << 32;
	if ((ret = align_word((const unsigned char **)&s, (unsigned char)c, &n)) != NULL)
		return (ret);
	word_search((const unsigned long **)&s, cccc, &n);
	if ((ret = byte_search((const unsigned char **)&s, (unsigned char)c, &n)) != NULL)
		return (ret);
	return (NULL);
}
