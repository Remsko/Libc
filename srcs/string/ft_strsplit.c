/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:46:52 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/13 17:50:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "string_42.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	words;
	size_t	length;

	if (s == NULL || (split = (char **)malloc(sizeof(char *)
		* (ft_strwords(s, c) + 1))) == NULL)
		return (NULL);
	words = 0;
	while (*s != '\0')
	{
		if (*s == c)
			++s;
		else
		{
			length = 0;
			while (s[length] != '\0' && s[length] != c)
				++length;
			if ((split[words++] = ft_strndup(s, length)) == NULL)
				return (NULL);
			s += length;
		}
	}
	split[words] = NULL;
	return (split);
}
