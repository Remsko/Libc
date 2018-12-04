/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:48:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 16:42:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp_nb;

	tmp_nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp_nb = -n;
	}
	if (tmp_nb > 9)
	{
		ft_putnbr_fd(tmp_nb / 10, fd);
		ft_putnbr_fd(tmp_nb % 10, fd);
	}
	else
		ft_putchar_fd(tmp_nb + '0', fd);
}
