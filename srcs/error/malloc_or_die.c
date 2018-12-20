/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_or_die.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:58:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 17:37:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "error_42.h"

void    malloc_or_die(void **ptr, size_t size, char *where)
{
    if (ptr != NULL)
    {
        *ptr = malloc(size);
        if (*ptr == NULL)
            error_malloc(where);
    }
}