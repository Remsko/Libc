/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 21:55:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/23 21:55:58 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t  ft_splitlen(char **split)
{
    size_t length;

    length = 0;
    if (split != NULL)
    {
        while (split[length] != NULL)
            ++length;
    }
    return (length);
}