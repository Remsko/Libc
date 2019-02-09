/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:26:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 14:34:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "queue_42.h"

void en_queue(t_queue *queue, int k)
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