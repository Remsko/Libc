/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:20:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:59:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue_42.h"

size_t	de_queue(t_queue *queue)
{
	size_t	key;
	t_qnode	*node;

	if (queue == NULL || queue->front == NULL)
		return (0);
	node = queue->front;
	queue->front = node->next;
	if (queue->front == NULL)
		queue->rear = NULL;
	key = node->key;
	free(node);
	return (key);
}
