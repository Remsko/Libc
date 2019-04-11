/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:44:21 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:50:05 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_2d_char(void *ptr, size_t length)
{
	char	**tmp;
	size_t	index;

	tmp = (char **)ptr;
	index = 0;
	if (tmp != NULL)
	{
		while (index < length)
		{
			if (tmp[index] != NULL)
				free(tmp[index]);
			++index;
		}
		free(tmp);
	}
}
