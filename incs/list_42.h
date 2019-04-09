/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:38:11 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 21:51:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_42_H
# define LIST_42_H

typedef struct	s_list
{
	struct s_list *prev;
	struct s_list *next;
}				t_list;

# define LST_ENTRY(p, t, m) ((t *)((char *)(p) - (unsigned long)(&((t *)0)->m)))

void			list_head_init(t_list *head);
void			list_del(t_list *prev, t_list *next);
void			list_insert(t_list *newp, t_list *prev, t_list *next);
void			list_add(t_list *newp, t_list *head);

#endif
