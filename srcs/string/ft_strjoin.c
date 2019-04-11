/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:13:29 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:24:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if ((ret = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))) != NULL)
	{
		ft_memcpy(ret, s1, len_s1);
		ft_memcpy(ret + len_s1, s2, len_s2 + 1);
	}
	return (ret);
}
