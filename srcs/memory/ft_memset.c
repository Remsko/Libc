/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:38:34 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/10 14:08:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

static inline void	copy_by64byte(long int dst_ptr, unsigned long int cccc)
{
	((unsigned long int *)dst_ptr)[0] = cccc;
	((unsigned long int *)dst_ptr)[1] = cccc;
	((unsigned long int *)dst_ptr)[2] = cccc;
	((unsigned long int *)dst_ptr)[3] = cccc;
	((unsigned long int *)dst_ptr)[4] = cccc;
	((unsigned long int *)dst_ptr)[5] = cccc;
	((unsigned long int *)dst_ptr)[6] = cccc;
	((unsigned long int *)dst_ptr)[7] = cccc;
}

static inline void	copy_by8and64byte(long int *dst_ptr, size_t *len, \
		unsigned long int cccc)
{
	size_t xlen;

	xlen = *len / MEM_BLOCK_SIZE;
	while (xlen > 0)
	{
		copy_by64byte(*dst_ptr, cccc);
		*dst_ptr += MEM_BLOCK_SIZE;
		xlen -= 1;
	}
	*len %= 64;
	xlen = *len / MEM_WORD_LEN;
	while (xlen > 0)
	{
		((unsigned long int *)*dst_ptr)[0] = cccc;
		*dst_ptr += MEM_WORD_LEN;
		xlen -= 1;
	}
	*len %= MEM_WORD_LEN;
}

void				*ft_memset(void *dst, int c, size_t len)
{
	long int			dst_ptr;
	unsigned long int	cccc;

	dst_ptr = (long int)dst;
	if (len >= MEM_WORD_LEN)
	{
		cccc = (unsigned char)c;
		cccc |= cccc << 8;
		cccc |= cccc << 16;
		cccc |= cccc << 32;
		while (dst_ptr % MEM_WORD_LEN != 0)
		{
			((unsigned char *)dst_ptr)[0] = c;
			dst_ptr += 1;
			len -= 1;
		}
		copy_by8and64byte(&dst_ptr, &len, cccc);
	}
	while (len > 0)
	{
		((unsigned char *)dst_ptr)[0] = c;
		dst_ptr += 1;
		len -= 1;
	}
	return (dst);
}
