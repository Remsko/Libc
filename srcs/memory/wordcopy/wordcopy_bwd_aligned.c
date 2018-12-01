/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordcopy_bwd_aligned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:07:47 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/01 14:13:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void wordcopy_bwd_aligned(long int dstp, long int srcp, size_t len)
{
    unsigned long int a0, a1;

    switch (len % 8)
    {
    case 2:
        srcp -= 2 * MEM_WORD_LEN;
        dstp -= 1 * MEM_WORD_LEN;
        a0 = ((unsigned long int *)srcp)[1];
        len += 6;
        goto do1;
    case 3:
        srcp -= 3 * MEM_WORD_LEN;
        dstp -= 2 * MEM_WORD_LEN;
        a1 = ((unsigned long int *)srcp)[2];
        len += 5;
        goto do2;
    case 4:
        srcp -= 4 * MEM_WORD_LEN;
        dstp -= 3 * MEM_WORD_LEN;
        a0 = ((unsigned long int *)srcp)[3];
        len += 4;
        goto do3;
    case 5:
        srcp -= 5 * MEM_WORD_LEN;
        dstp -= 4 * MEM_WORD_LEN;
        a1 = ((unsigned long int *)srcp)[4];
        len += 3;
        goto do4;
    case 6:
        srcp -= 6 * MEM_WORD_LEN;
        dstp -= 5 * MEM_WORD_LEN;
        a0 = ((unsigned long int *)srcp)[5];
        len += 2;
        goto do5;
    case 7:
        srcp -= 7 * MEM_WORD_LEN;
        dstp -= 6 * MEM_WORD_LEN;
        a1 = ((unsigned long int *)srcp)[6];
        len += 1;
        goto do6;

    case 0:
        if (MEM_THRESHOLD <= 3 * MEM_WORD_LEN && len == 0)
            return;
        srcp -= 8 * MEM_WORD_LEN;
        dstp -= 7 * MEM_WORD_LEN;
        a0 = ((unsigned long int *)srcp)[7];
        goto do7;
    case 1:
        srcp -= 9 * MEM_WORD_LEN;
        dstp -= 8 * MEM_WORD_LEN;
        a1 = ((unsigned long int *)srcp)[8];
        len -= 1;
        if (MEM_THRESHOLD <= 3 * MEM_WORD_LEN && len == 0)
            goto do0;
        goto do8; /* No-op.  */
    }

    do
    {
    do8:
        a0 = ((unsigned long int *)srcp)[7];
        ((unsigned long int *)dstp)[7] = a1;
    do7:
        a1 = ((unsigned long int *)srcp)[6];
        ((unsigned long int *)dstp)[6] = a0;
    do6:
        a0 = ((unsigned long int *)srcp)[5];
        ((unsigned long int *)dstp)[5] = a1;
    do5:
        a1 = ((unsigned long int *)srcp)[4];
        ((unsigned long int *)dstp)[4] = a0;
    do4:
        a0 = ((unsigned long int *)srcp)[3];
        ((unsigned long int *)dstp)[3] = a1;
    do3:
        a1 = ((unsigned long int *)srcp)[2];
        ((unsigned long int *)dstp)[2] = a0;
    do2:
        a0 = ((unsigned long int *)srcp)[1];
        ((unsigned long int *)dstp)[1] = a1;
    do1:
        a1 = ((unsigned long int *)srcp)[0];
        ((unsigned long int *)dstp)[0] = a0;

        srcp -= 8 * MEM_WORD_LEN;
        dstp -= 8 * MEM_WORD_LEN;
        len -= 8;
    } while (len != 0);

    /* This is the right position for do0.  Please don't move
     it into the loop.  */
do0:
    ((unsigned long int *)dstp)[7] = a1;
}