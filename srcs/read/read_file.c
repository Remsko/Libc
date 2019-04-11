/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:06:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:21:44 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "memory_42.h"
#include "read_42.h"

char	*read_file(int fd)
{
	char	buff[BUFF_SIZE];
	char	*str;
	ssize_t	rtotal;
	ssize_t	rret;

	str = NULL;
	rtotal = 0;
	while ((rret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		str = ft_realloc(str, rtotal + rret + 1, rtotal);
		ft_memcpy(str + rtotal, buff, rret);
		str[rtotal + rret] = '\0';
		rtotal += rret;
	}
	if (rret == -1)
		free(str);
	return (str);
}
