/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_push_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:08:16 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/02 02:16:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll_42.h"

void dll_push_front(t_dll **head, void *content)  
{
	t_dll *new;

	if ((new = malloc(sizeof(t_dll))) == NULL)
		return ;
	new->content = content;  
	new->prev = NULL;  
	new->next = *head;  
	if (*head != NULL)  
		(*head)->prev = new;  
	*head = new;  
} 