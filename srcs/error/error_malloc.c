/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:45:12 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/13 14:48:43 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "write_42.h"

void    error_malloc(void)
{
    ft_putstr("Error: malloc returned NULL !\n");
    exit(EXIT_FAILURE);
}