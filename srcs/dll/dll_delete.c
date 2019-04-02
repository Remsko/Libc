/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 02:13:27 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/02 02:16:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dll_42.h"

void dll_delete(t_dll **head_ref, t_dll *delete, void (del)(void *))
{
	if (*head_ref == NULL || delete == NULL)  
		return ;
	if (*head_ref == delete)  
		*head_ref = delete->next;  
	if (delete->next != NULL)  
		delete->next->prev = delete->prev;  
	if (delete->prev != NULL)  
		delete->prev->next = delete->next;  
	del(delete->content);
	free(delete);  
	return; 
}