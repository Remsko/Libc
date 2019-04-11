/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:28:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:49:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"

int	error_throw(t_error *err)
{
	int ret;

	if (err == NULL)
		return (0);
	if (err->msg != NULL)
	{
		if (err->msg_printf != NULL)
			err->msg_printf(err->msg);
		if (err->msg_freef != NULL)
			err->msg_freef(err->msg);
	}
	ret = (int)err->status;
	free(err);
	return (ret);
}
