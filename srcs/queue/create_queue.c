/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:10:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:58:12 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue_42.h"
#include "memory_42.h"

t_queue	*create_queue(void)
{
	t_queue *queue;

	if ((queue = (t_queue *)malloc(sizeof(t_queue))) != NULL)
		ft_bzero((void *)queue, sizeof(t_queue));
	return (queue);
}
