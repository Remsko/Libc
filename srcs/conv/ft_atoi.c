/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:57:05 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 15:59:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ascii_42.h"

int		ft_atoi(const char *str)
{
	unsigned char	neg;
	int				nb;

	while (ft_isspace((int)*str))
		++str;
	neg = (*str == '-');
	if (*str == '+' || *str == '-')
		++str;
	nb = 0;
	while (ft_isdigit((int)*str))
	{
		nb = nb * 10 + (*str - '0');
		++str;
	}
	return (neg ? -nb : nb);
}
