/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:14:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/10 14:14:37 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char *ft_strrchr(const char *s, int c)
{
	const char *found;
	const char *ptr;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while ((ptr = ft_strchr(s, c)) != NULL)
	{
		found = ptr;
		s = ptr + 1;
	}
	return ((char *)found);
}