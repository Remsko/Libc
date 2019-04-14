/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:38:34 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 19:01:23 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

inline static void	align_word(unsigned char **pdst, unsigned char c, size_t *n)
{
	while (*n > 0 && (size_t)*pdst % MEM_WORD_LEN)
	{
		(*pdst)[0] = c;
		*pdst += 1;
		*n -= 1;
	}
}

inline static void	set_blocks(unsigned long **pdst, unsigned long cccc, size_t blocks)
{
	while (blocks > 0)
	{
		(*pdst)[0] = cccc;
		(*pdst)[1] = cccc;
		(*pdst)[2] = cccc;
		(*pdst)[3] = cccc;
		(*pdst)[4] = cccc;
		(*pdst)[5] = cccc;
		(*pdst)[6] = cccc;
		(*pdst)[7] = cccc;
		*pdst += 8;
		blocks -= 1;
	}
}

inline static void	set_words(unsigned long **pdst, unsigned long cccc, size_t words)
{
	while (words > 0)
	{
		(*pdst)[0] = cccc;
		*pdst += 1;
		words -= 1;
	}
}

inline static void	set_bytes(unsigned char **pdst, unsigned char c, size_t bytes)
{
	while (bytes > 0)
	{
		(*pdst)[0] = c;
		*pdst += 1;
		bytes -= 1;
	}
}

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned long	cccc;

	if (n >= MEM_WORD_LEN)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= cccc << 32;
		align_word((unsigned char **)&s, (unsigned char)c, &n);
		set_blocks((unsigned long **)&s, cccc, n / MEM_BLOCK_SIZE);
		n %= MEM_BLOCK_SIZE;
		set_words((unsigned long **)&s, cccc, n / MEM_WORD_LEN);
		n %= MEM_WORD_LEN;
	}
	set_bytes((unsigned char **)&s, (unsigned char)c, n);
	return (s);
}
