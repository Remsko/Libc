/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:01:51 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:21:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdbool.h>
#include "read_42.h"
#include "memory_42.h"
#include "string_42.h"

static int	extract_line(char **pos, char **line, size_t start)
{
	char *newl;

	if ((newl = ft_strchr(*pos + start, (int)'\n')) == NULL)
		return (false);
	*line = ft_strsub(*pos, 0, newl - *pos);
	ft_memcpy(*pos, newl + 1, ft_strlen(newl));
	return (true);
}

static int	read_loop(const int fd, char **line, char **pos)
{
	char		buff[BUFF_SIZE];
	ssize_t		rtotal;
	ssize_t		rret;

	rtotal = (*pos != NULL) ? ft_strlen(*pos) : 0;
	while ((rret = read(fd, buff, BUFF_SIZE)))
	{
		if (rret == -1)
		{
			free(*pos);
			return (-1);
		}
		*pos = ft_realloc(*pos, rtotal + rret + 1, rtotal);
		ft_memcpy(*pos + rtotal, buff, rret);
		(*pos)[rtotal + rret] = '\0';
		if (extract_line(pos, line, rtotal))
			return (1);
		rtotal += rret;
	}
	ft_strdel(pos);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*pos = NULL;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (pos != NULL && extract_line(&pos, line, 0))
		return (1);
	if ((ret = read_loop(fd, line, &pos)))
		return (ret);
	*line = pos;
	return ((*line != NULL));
}
