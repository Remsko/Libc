/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:28:37 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 18:02:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "error_42.h"
#include "string_42.h"
#include "write_42.h"

void    error_throw(t_error *err, void (*strfy)(t_status), bool debug_mode)
{
    if (err != NULL)
    {
        if (err->msg != NULL)
        {
            ft_putendl_fd(err->msg, 2);
            ft_strdel(&err->msg);
        }
        if (err->debug != NULL)
        {
            if (debug_mode == true)
                ft_putendl_fd(err->debug, 2);
            ft_strdel(&err->debug);
        }
        if (strfy != NULL)
        {
            ft_putendl_fd("Exit on status: ", 2);
            strfy(err->status);
        }
        free(err);
    }
}