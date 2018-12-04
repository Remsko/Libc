/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:35:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 16:00:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		tmp;

	len = (n <= 0);
	tmp = n;
	while (++len && tmp)
		tmp /= 10;
	if ((str = (char*)malloc(sizeof(char) * (len))) == NULL)
		return (NULL);
	str[--len] = '\0';
	tmp = (n < 0) ? -1 : 1;
	while (len)
	{
		str[--len] = (n % 10) * tmp + '0';
		n /= 10;
	}
	tmp < 0 ? *str = '-' : 0;
	return (str);
}
