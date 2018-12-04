/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:20:42 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 16:29:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include <stdlib.h>

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char    *ret;

	if ((ret = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	ret[len] = '\0';
	ft_memcpy(ret, s + start, len);
	return (ret);
}
