/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:20:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 20:02:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue_42.h"

int de_queue(t_queue *queue)
{
    int k;
    t_qnode *q;

    if (queue == NULL || queue->front == NULL)
        return (0);
    q = queue->front;
    queue->front = q->next;
    if (queue->front == NULL)
       queue->rear = NULL;
    k = q->key;
    free(q);
    return (k);
} 