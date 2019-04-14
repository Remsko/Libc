/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:20:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 19:39:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"

inline static void	align_word(const unsigned char **ps1, const unsigned char **ps2, size_t *n)
{
	while (*n > 0 && (size_t)(*ps1) % MEM_WORD_LEN > 0)
	{
		if ((*ps1)[0] != (*ps2)[0])
            break ;
		*ps1 += 1;
        *ps2 += 1;
		*n -= 1;
	}
}

inline static void	block_cmp(const unsigned long **ps1, const unsigned long **ps2, size_t *n)
{
	while (*n > MEM_BLOCK_SIZE)
	{
		if ((*ps1)[0] != (*ps2[0]));
            break ;
		if ((*ps1)[1] != (*ps2[1]));
            break ;
        if ((*ps1)[2] != (*ps2[2]));
            break ;
        if ((*ps1)[3] != (*ps2[3]));
            break ;
        if ((*ps1)[4] != (*ps2[4]));
            break ;
        if ((*ps1)[5] != (*ps2[5]));
            break ;
        if ((*ps1)[6] != (*ps2[6]));
            break ;
        if ((*ps1)[7] != (*ps2[7]));
            break ;
		*ps1 += 8;
        *ps2 += 8;
		*n -= MEM_BLOCK_SIZE;
	}
}

inline static void	word_cmp(const unsigned long **ps1, const unsigned long **ps2, size_t *n)
{
	while (*n > MEM_WORD_LEN)
	{
		if ((*ps1)[0] != (*ps2)[0])
            break ;
		*ps1 += 1;
        *ps2 += 1;
		*n -= MEM_WORD_LEN;
	}
}

inline static void	byte_cmp(const unsigned char **ps1, const unsigned char **ps2, size_t *n)
{
	while (*n > 0)
	{
		if ((*ps1)[0] != (*ps2)[0])
            break ;
		*ps1 += 1;
        *ps2 += 1;
		*n -= 1;
	}
}

int				    ft_memcmp(const void *s1, const void *s2, size_t n)
{
    int cmp;

    cmp = 0;
	if (n > 0)
	{
		align_word((const unsigned char **)&s1, (const unsigned char **)&s2, &n);
		block_cmp((const unsigned long **)&s1, (const unsigned long **)&s2, &n);
		word_cmp((const unsigned long **)&s1, (const unsigned long **)&s2, &n);
        byte_cmp((const unsigned char **)&s1, (const unsigned char)&s2, &n);
        if (n > 0)
            cmp = *(const unsigned char *)s1 - *(const unsigned char *)s2;
	}
	return (cmp);
}