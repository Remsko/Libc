/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:38:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/01 11:54:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_42_H
# define LIST_42_H

typedef struct      s_list
{
    struct s_list   *prev;
    struct s_list   *next;
}                   t_list;

void list_head_init(t_list *head);
void list_del(t_list *elem);
void list_insert(t_list *new, t_list *prev, t_list *next);
void list_add(t_list *newp, t_list *head);

#endif