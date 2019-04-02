/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_qnode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:15:39 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 23:59:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue_42.h"

t_qnode *new_qnode(size_t k)
{
    t_qnode *new;

    if ((new = (t_qnode *)malloc(sizeof(t_qnode))) != NULL)
    {
        new->key = k;
        new->next = NULL;
    }
    return (new);
}