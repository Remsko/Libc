/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:45:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 17:31:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "write_42.h"

void    error_malloc(char *where)
{
    ft_putstr_fd("Error: malloc returned NULL in ", 2);
    ft_putendl_fd(where, 2);
    exit(EXIT_FAILURE);
}