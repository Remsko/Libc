/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:23:20 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 16:44:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_42.h"
#include "string_42.h"
#include <unistd.h>

void	ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	ft_putchar('\n');
}