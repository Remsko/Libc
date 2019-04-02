/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:26:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/01 23:59:20 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "queue_42.h"

void en_queue(t_queue *queue, size_t k)
{
    t_qnode *new;

    if (queue == NULL)
        return ;
    new = new_qnode(k);
    if (queue->rear == NULL)
    {
        queue->front = new;
        queue->rear = new;
        return ;
    }
    queue->rear->next = new;
    queue->rear = new;
}