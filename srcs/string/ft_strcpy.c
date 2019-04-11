/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:01:36 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:22:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_42.h"
#include "string_42.h"

char	*ft_strcpy(char *dest, const char *src)
{
	return ((char *)ft_memcpy(dest, src, ft_strlen(src) + 1));
}
