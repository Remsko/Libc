/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:46:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/12 17:20:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void byte_copy_forward(unsigned long int dst_bp, unsigned long int src_bp, size_t nbytes)
{
    while (nbytes > 0)
    {
        ((unsigned char *)dst_bp)[0] = ((unsigned char *)src_bp)[0];
        src_bp += 1;
        dst_bp += 1;
        nbytes -= 1;
    }
}

void word_copy_forward(unsigned long int dst_bp, unsigned long int src_bp, size_t nbytes_left, size_t nbytes)
{
    if (src_bp % MEM_WORD_LEN == 0)
        wordcopy_fwd_aligned(dst_bp, src_bp, (nbytes) / MEM_WORD_LEN);
    else
        wordcopy_fwd_dest_aligned(dst_bp, src_bp, (nbytes) / MEM_WORD_LEN);
    src_bp += (nbytes) & -MEM_WORD_LEN;
    dst_bp += (nbytes) & -MEM_WORD_LEN;
    (nbytes_left) = (nbytes) % MEM_WORD_LEN;
}

void *ft_memcpy(void *dstpp, const void *srcpp, size_t len)
{
    unsigned long int dstp;
    unsigned long int srcp;

    dstp = (long int)dstpp;
    srcp = (long int)srcpp;
    if (len >= MEM_THRESHOLD)
    {
        len -= (-dstp) % MEM_WORD_LEN;
        byte_copy_forward(dstp, srcp, (-dstp) % MEM_WORD_LEN);
        word_copy_forward(dstp, srcp, len, len);
    }
    byte_copy_forward(dstp, srcp, len);
    return (dstpp);
}