/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:58:18 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/11 20:05:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_42_H
#define QUEUE_42_h

#include <stdbool.h>

typedef struct s_qnode
{ 
    int key; 
    struct s_qnode *next;
} t_qnode; 
  
typedef struct s_queue 
{
    t_qnode *front;
    t_qnode *rear;
} t_queue;

t_queue *create_queue(void);

t_qnode *new_qnode(int k);

int de_queue(t_queue *queue);

void en_queue(t_queue *queue, int k);

bool is_queue(t_queue *queue);

#endif