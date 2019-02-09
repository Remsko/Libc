/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:20:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 14:25:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "queue_42.h"

t_qnode *de_queue(t_queue *queue)
{
    t_qnode *ret;

    if (queue == NULL || queue->front == NULL)
        return (NULL);
    ret = queue->front;
    queue->front = ret->next;
    if (queue->front == NULL)
       queue->rear = NULL;
    return (ret);
} 