/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:56:47 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:23:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

char	*ft_strdup(const char *s)
{
	void	*new;
	size_t	len;

	len = ft_strlen(s) + 1;
	if ((new = malloc(len)) == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s, len));
}
