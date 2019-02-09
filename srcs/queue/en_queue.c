/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:26:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/09 14:29:42 by rpinoit          ###   ########.fr       */
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

/*
void enQueue(struct Queue *q, int k) 
{ 
    // Create a new LL node 
    struct QNode *temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 
*/