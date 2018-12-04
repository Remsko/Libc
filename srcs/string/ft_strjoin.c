/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:13:29 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 16:23:13 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"
#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	len[2];
	char	*ret;
	
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	if ((ret = (char *)malloc(sizeof(char) * (len[0] + len[1] + 1))) != NULL)
	{
		ft_memcpy(ret, s1, len[0]);
		ft_memcpy(ret + len[0], s2, len[1] + 1);
	}
	return (ret);
}
