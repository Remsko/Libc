/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:44:21 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/20 17:49:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    free_2d_char(void *ptr, size_t size)
{
    char    **tmp;
    size_t  i;

    tmp = (char **)ptr;
    i = 0;
    while (i < size)
    {
        if (tmp[i] != NULL)
            free(tmp[i]);
        ++i;
    }
    free(tmp);
}