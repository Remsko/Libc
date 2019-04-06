/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:58:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/06 16:53:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_42_H
# define QUEUE_42_H

# include <stdbool.h>

typedef struct	s_qnode
{
	size_t			key;
	struct s_qnode	*next;
}				t_qnode;

typedef struct	s_queue
{
	t_qnode *front;
	t_qnode *rear;
}				t_queue;

t_queue			*create_queue(void);

t_qnode			*new_qnode(size_t k);

size_t			de_queue(t_queue *queue);

void			en_queue(t_queue *queue, size_t k);

bool			is_queue(t_queue *queue);

#endif
