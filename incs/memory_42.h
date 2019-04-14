/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:37:01 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/14 19:18:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_42_H
# define MEMORY_42_H

# include <stdlib.h>

# define MEM_WORD_LEN (sizeof(unsigned long int))
# define MEM_BLOCK_SIZE (8 * MEM_WORD_LEN)
# define MASK80 (0x8080808080808080UL)
# define MASK01 (0x0101010101010101UL)

void *ft_memalloc(size_t size);
void *ft_realloc(void *p, size_t new, size_t old);
void ft_memdel(void **ap);
void *ft_memcpy(void *dstpp, const void *srcpp, size_t len);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_mempcpy(void *dst, const void *src, size_t len);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
void *ft_memset(void *dst, int c, size_t len);
void *ft_memchr(void const *s, int c, size_t n);
void ft_bzero(void *s, size_t len);

#endif
