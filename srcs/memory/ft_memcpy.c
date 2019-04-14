/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:46:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 19:12:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

inline static void	align_word_fwd(unsigned char **pdst, const unsigned char **psrc, size_t *n)
{
	while (*n > 0 && (size_t)(*pdst) % MEM_WORD_LEN > 0)
	{
		(*pdst)[0] = (*psrc)[0];
		*pdst += 1;
		*psrc += 1;
		*n -= 1;
	}
}

inline static void	block_copy_fwd(unsigned long **pdst, const unsigned long **psrc, size_t blocks)
{
	while (blocks > 0)
	{
		(*pdst)[0] = (*psrc)[0];
		(*pdst)[1] = (*psrc)[1];
		(*pdst)[2] = (*psrc)[2];
		(*pdst)[3] = (*psrc)[3];
		(*pdst)[4] = (*psrc)[4];
		(*pdst)[5] = (*psrc)[5];
		(*pdst)[6] = (*psrc)[6];
		(*pdst)[7] = (*psrc)[7];
		*pdst += 8;
		*psrc += 8;
		blocks -= 1;
	}
}

inline static void	 word_copy_fwd(unsigned long **pdst, const unsigned long **psrc, size_t words)
{
	while (words > 0)
	{
		(*pdst)[0] = (*psrc)[0];
		*pdst += 1;
		*psrc += 1;
		words -= 1;
	}
}

inline static void	byte_copy_fwd(unsigned char **pdst, const unsigned char **psrc, size_t bytes)
{
	while (bytes > 0)
	{
		(*pdst)[0] = (*psrc)[0];
		*pdst += 1;
		*psrc += 1;
		bytes -= 1;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *p;

	p = dst;
	if (n >= MEM_WORD_LEN)
	{
		align_word_fwd((unsigned char **)&dst, (const unsigned char **)&src, &n);
		block_copy_fwd((unsigned long **)&dst, (const unsigned long **)&src, n / MEM_BLOCK_SIZE);
		n %= MEM_BLOCK_SIZE;
		word_copy_fwd((unsigned long **)&dst, (const unsigned long **)&src, n / MEM_WORD_LEN);
		n %= MEM_WORD_LEN;
	}
	byte_copy_fwd((unsigned char **)&dst, (const unsigned char **)&src, n);
	return (p);
}
