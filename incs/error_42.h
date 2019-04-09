/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:46:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 21:43:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_42_H
# define ERROR_42_H

# include <stdbool.h>
# include <stddef.h>

typedef unsigned char	t_status;

typedef struct	s_error
{
	void		*msg;
	void		(*msg_printf)(void *msg);
	void		(*msg_freef)(void *msg);
	t_status	status;
}				t_error;

void			error_malloc_exit(char *where);
t_error			*error_create(void *msg, void (*msg_printf)(void *msg),
					void (*msg_freef)(void *msg), t_status status);
int				error_throw(t_error *err);
void			malloc_or_die(void **ptr, size_t size, char *where);

#endif
