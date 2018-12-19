/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_throw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:28:37 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/19 11:55:08 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include "error_42.h"
#include "string_42.h"
#include "write_42.h"

void    error_throw(t_error *err, void (*strfy)(t_status), bool debug_mode)
{
    if (err != NULL)
    {
        ft_putstr_fd(err->msg, 2);
        if (debug_mode == true)
            ft_putendl_fd(err->debug, 2);
        ft_putstr_fd("Exit on status: ", 2);
        strfy(err->status);
        ft_putstr_fd("\n", 2);
    }
}