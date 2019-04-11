/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:22:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:57:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

#define BYTE_COPY_BWD(dst_ep, src_ep, nbytes)                            \
	do                                                                   \
{                                                                    \
	size_t bytes = (nbytes);                                         \
	while (bytes > 0)                                                \
	{                                                                \
		src_ep -= 1;                                                 \
		((unsigned char *)dst_ep)[0] = ((unsigned char *)src_ep)[0]; \
		dst_ep -= 1;                                                 \
		bytes -= 1;                                                  \
	}                                                                \
} while (0)

#define WORD_COPY_BWD(dst_ep, src_ep, nbytes_left, nbytes)                      \
	do                                                                          \
{                                                                           \
	if (src_ep % MEM_WORD_LEN == 0)                                         \
	wordcopy_bwd_aligned(dst_ep, src_ep, (nbytes) / MEM_WORD_LEN);      \
	else                                                                    \
	wordcopy_bwd_dest_aligned(dst_ep, src_ep, (nbytes) / MEM_WORD_LEN); \
	src_ep -= (nbytes) & -MEM_WORD_LEN;                                     \
	dst_ep -= (nbytes) & -MEM_WORD_LEN;                                     \
	(nbytes_left) = (nbytes) % MEM_WORD_LEN;                                \
} while (0)

void *ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned long int dstp = (long int)dest;
	unsigned long int srcp = (long int)src;

	if (dstp - srcp >= len)
		dest = ft_memcpy(dest, src, len);
	else
	{
		srcp += len;
		dstp += len;
		if (len >= MEM_THRESHOLD)
		{
			len -= dstp % MEM_WORD_LEN;
			BYTE_COPY_BWD(dstp, srcp, dstp % MEM_WORD_LEN);
			WORD_COPY_BWD(dstp, srcp, len, len);
		}
		BYTE_COPY_BWD(dstp, srcp, len);
	}
	return (dest);
}
