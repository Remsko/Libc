/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_42.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:09:14 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/06 16:45:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_42_H
# define DLL_42_H

typedef struct	s_dll
{
	struct s_dll	*next;
	struct s_dll	*prev;
	void			*content;
}				t_dll;

void			dll_delete(t_dll **head, t_dll *delete, void (del)(void *));

void			dll_push_front(t_dll **head, void *content);

#endif
