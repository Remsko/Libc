/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:24:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/27 15:27:47 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_42_H
# define ARRAY_42_H

typedef struct	s_array
{
	void	*content;
	size_t	length;
	size_t	capacity;
	size_t	memory;
}				t_array;

#endif
