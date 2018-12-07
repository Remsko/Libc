/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:48:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/04 17:50:46 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "string_42.h"
#include "conv_42.h"

bool	ft_isatoi(char *str, int *n)
{
	char	*cmp;
	bool	ret;

	*n = ft_atoi(str);
	cmp = ft_itoa(*n);
	ret = ft_strequ(str, cmp);
	ft_strdel(&cmp);
	return (ret);
}
