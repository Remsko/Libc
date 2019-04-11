/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 12:58:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:27:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strwords(const char *s, char c)
{
	size_t	words;
	size_t	flag;

	words = 0;
	flag = 0;
	if (s != NULL)
	{
		while (*s != '\0')
		{
			if (*s == c)
				flag = 0;
			else if (flag == 0)
			{
				flag = 1;
				++words;
			}
			++s;
		}
	}
	return (words);
}
