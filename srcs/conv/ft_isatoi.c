/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isatoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:48:28 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 20:53:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "string_42.h"
#include "conv_42.h"

bool	ft_isatoi(char *str, int *n)
{
	char	*cmp;
	bool	ret;

	if (str == NULL || n == NULL)
		return (false);
	*n = ft_atoi(str);
	if ((cmp = ft_itoa(*n)) == NULL)
		return (false);
	ret = ft_strequ(str, cmp);
	ft_strdel(&cmp);
	return (ret);
}
