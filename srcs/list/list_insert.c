/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:20:33 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:50:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_42.h"

inline void	list_insert(t_list *newp, t_list *prev, t_list *next)
{
	next->prev = newp;
	newp->next = next;
	newp->prev = prev;
	prev->next = newp;
}
