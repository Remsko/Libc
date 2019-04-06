/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:50:09 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/06 16:45:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_42_H
# define FREE_42_H

# include <stddef.h>

void	free_1d_char(void *ptr, size_t length);

void	free_2d_char(void *ptr, size_t size);

#endif
