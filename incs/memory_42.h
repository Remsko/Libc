/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:37:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/12 17:20:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_42_H
# define MEMORY_42_H

# include <stdlib.h>

# define MEM_WORD_LEN	(sizeof(unsigned long int))
# define MEM_BLOCK_SIZE	(8 * MEM_WORD_LEN)
# define MEM_PAGE_SIZE	(4096)
# define MEM_THRESHOLD	(2 * MEM_WORD_LEN)
# define OVER_HEIGHT	(0xFFFFFFFFFFFFFFF8UL)
# define MASK80		(0x8080808080808080UL)
# define MASK01		(0x0101010101010101UL)

void *ft_memcpy(void *dstpp, const void *srcpp, size_t len);

#endif
