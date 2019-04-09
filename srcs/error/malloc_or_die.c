/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_or_die.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:58:27 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 21:21:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"

void    malloc_or_die(void **ptr, size_t size, char *where)
{
    if (ptr != NULL)
    {
        if ((*ptr = malloc(size)) != NULL)
            return ;
        error_malloc_exit(where);
    }
}