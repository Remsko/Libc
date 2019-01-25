/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:41:40 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 18:09:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "error_42.h"
#include "string_42.h"

t_error *error_create(char *msg, char *debug, t_status status)
{
    t_error *err;

    if ((err = (t_error *)malloc(sizeof(t_error))) == NULL)
        error_malloc("in error_create function line 22.");
    if (msg != NULL)
    {
        if ((err->msg = ft_strdup(msg)) == NULL)
            error_malloc("in error_create function line 24.");
    }
    else
        err->msg = NULL;
    if (debug != NULL)
    {
        if ((err->debug = ft_strdup(debug)) == NULL)
            error_malloc("in error_create function line 26.");
    }
    else
        err->debug = NULL;
    err->status = status;
    return (err);
}