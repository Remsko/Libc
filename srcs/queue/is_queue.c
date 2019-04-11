/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:03:57 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:58:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "queue_42.h"

bool	is_queue(t_queue *queue)
{
	return (queue->front != NULL);
}
