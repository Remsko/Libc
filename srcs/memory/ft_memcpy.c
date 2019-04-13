/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:46:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/13 23:02:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

#define BYTE_COPY_FWD(dst_bp, src_bp, nbytes)                            \
	do                                                                   \
{                                                                    \
	size_t bytes = (nbytes);                                         \
	while (bytes > 0)                                                \
	{                                                                \
		((unsigned char *)dst_bp)[0] = ((unsigned char *)src_bp)[0]; \
		src_bp += 1;                                                 \
		dst_bp += 1;                                                 \
		bytes -= 1;                                                  \
	}                                                                \
} while (0)

#define WORD_COPY_FWD(dst_bp, src_bp, nbytes_left, nbytes)                      \
	do                                                                          \
{                                                                           \
	if (src_bp % MEM_WORD_LEN == 0)                                         \
	wordcopy_fwd_aligned(dst_bp, src_bp, (nbytes) / MEM_WORD_LEN);      \
	else                                                                    \
	wordcopy_fwd_dest_aligned(dst_bp, src_bp, (nbytes) / MEM_WORD_LEN); \
	src_bp += (nbytes) & -MEM_WORD_LEN;                                     \
	dst_bp += (nbytes) & -MEM_WORD_LEN;                                     \
	(nbytes_left) = (nbytes) % MEM_WORD_LEN;                                \
} while (0)

void *ft_memcpy(void *dstpp, const void *srcpp, size_t len)
{
	unsigned long int dstp = (long int)dstpp;
	unsigned long int srcp = (long int)srcpp;

	if (len >= MEM_THRESHOLD)
	{
		len -= (-dstp) % MEM_WORD_LEN;

		BYTE_COPY_FWD(dstp, srcp, (-dstp) % MEM_WORD_LEN);

		WORD_COPY_FWD(dstp, srcp, len, len);
	}
	BYTE_COPY_FWD(dstp, srcp, len);
	return dstpp;
}
