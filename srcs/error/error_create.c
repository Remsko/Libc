/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:41:40 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 16:49:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"

t_error	*error_create(void *msg, void (*msg_printf)(void *msg),
			void (*msg_freef)(void *msg), t_status status)
{
	t_error *err;

	if ((err = (t_error *)malloc(sizeof(t_error))) == NULL)
		return (NULL);
	err->msg = msg;
	err->msg_printf = msg_printf;
	err->msg_freef = msg_freef;
	err->status = status;
	return (err);
}
