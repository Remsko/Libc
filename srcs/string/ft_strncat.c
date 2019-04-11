/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:59:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:24:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;
	size_t	ss;

	s = s1;
	s1 += ft_strlen(s1);
	ss = ft_strnlen(s2, n);
	s1[ss] = '\0';
	ft_memcpy(s1, s2, ss);
	return (s);
}
