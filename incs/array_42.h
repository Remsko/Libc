/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:24:28 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/06 16:39:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_42_H
# define ARRAY_42_H

# include <stddef.h>

# define MIN_CAPACITY (16U)

typedef struct	s_array
{
	void	*content;
	size_t	length;
	size_t	capacity;
	size_t	size;
}				t_array;

t_array			*array_create(size_t size);
void			*array_index(t_array *arr, size_t index);
void			array_append(t_array *arr, const void *src);
void			array_dispose(t_array *arr, void ft_free(void *, size_t));
void			array_insert(t_array *arr, void *p, size_t index);
void			array_resize_maybe(t_array *arr);
void			array_fit(t_array *arr);

#endif
