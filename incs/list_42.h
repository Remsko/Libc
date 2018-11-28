/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:38:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/28 17:42:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_42_H
# define LIST_42_H

typedef struct      s_list
{
    struct s_list   *prev;
    struct s_list   *next;
}                   t_list;

#endif