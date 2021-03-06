/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:30:25 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/13 22:14:06 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "memory_42.h"

void	*ft_realloc(void *p, size_t new, size_t old)
{
	void *ret;

	if ((ret = malloc(new)) != NULL)
		ft_memcpy(ret, p, old);
	free(p);
	return (ret);
}
