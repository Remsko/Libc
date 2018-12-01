/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordcopy_fwd_dest_aligned.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:42:35 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/01 11:44:18 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

void wordcopy_fwd_dest_aligned(long int dstp, long int srcp, size_t len)
{
    unsigned long int a0, a1, a2, a3;
    int sh_1, sh_2;

    /* Calculate how to shift a word read at the memory operation
     aligned srcp to make it aligned for copy.  */

    sh_1 = 8 * (srcp % MEM_WORD_LEN);
    sh_2 = 8 * MEM_WORD_LEN - sh_1;

    /* Make SRCP aligned by rounding it down to the beginning of the `unsigned long int'
     it points in the middle of.  */
    srcp &= -MEM_WORD_LEN;

    switch (len % 4)
    {
    case 2:
        a1 = ((unsigned long int *)srcp)[0];
        a2 = ((unsigned long int *)srcp)[1];
        srcp -= 1 * MEM_WORD_LEN;
        dstp -= 3 * MEM_WORD_LEN;
        len += 2;
        goto do1;
    case 3:
        a0 = ((unsigned long int *)srcp)[0];
        a1 = ((unsigned long int *)srcp)[1];
        srcp -= 0 * MEM_WORD_LEN;
        dstp -= 2 * MEM_WORD_LEN;
        len += 1;
        goto do2;
    case 0:
        if (MEM_THRESHOLD <= 3 * MEM_WORD_LEN && len == 0)
            return;
        a3 = ((unsigned long int *)srcp)[0];
        a0 = ((unsigned long int *)srcp)[1];
        srcp -= -1 * MEM_WORD_LEN;
        dstp -= 1 * MEM_WORD_LEN;
        len += 0;
        goto do3;
    case 1:
        a2 = ((unsigned long int *)srcp)[0];
        a3 = ((unsigned long int *)srcp)[1];
        srcp -= -2 * MEM_WORD_LEN;
        dstp -= 0 * MEM_WORD_LEN;
        len -= 1;
        if (MEM_THRESHOLD <= 3 * MEM_WORD_LEN && len == 0)
            goto do0;
        goto do4; /* No-op.  */
    }

    do
    {
    do4:
        a0 = ((unsigned long int *)srcp)[0];
        ((unsigned long int *)dstp)[0] = MERGE(a2, sh_1, a3, sh_2);
    do3:
        a1 = ((unsigned long int *)srcp)[1];
        ((unsigned long int *)dstp)[1] = MERGE(a3, sh_1, a0, sh_2);
    do2:
        a2 = ((unsigned long int *)srcp)[2];
        ((unsigned long int *)dstp)[2] = MERGE(a0, sh_1, a1, sh_2);
    do1:
        a3 = ((unsigned long int *)srcp)[3];
        ((unsigned long int *)dstp)[3] = MERGE(a1, sh_1, a2, sh_2);

        srcp += 4 * MEM_WORD_LEN;
        dstp += 4 * MEM_WORD_LEN;
        len -= 4;
    } while (len != 0);

    /* This is the right position for do0.  Please don't move
     it into the loop.  */
do0:
    ((unsigned long int *)dstp)[0] = MERGE(a2, sh_1, a3, sh_2);
}