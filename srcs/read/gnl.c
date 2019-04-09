/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:23:33 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/10 00:57:31 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "memory_42.h"
#include "read_42.h"
#include "string_42.h"


#include <stdio.h>
#include "string.h"

static void save_pos(char **ppos, char *newl)
{
	char *tmp;

	tmp = *ppos;
	*ppos = ft_memmove(*ppos, newl + 1, ft_strlen(newl));
	free(tmp);
}

static int	read_loop(const int fd, char **ppos, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*newl;
	size_t	rtotal;
	size_t	rret;

	rtotal = 0;
	while ((rret = read(fd, buff, BUFF_SIZE)))
	{
		if (rret == -1)
			return (-1);
		buff[rret] = '\0';
		*ppos = ft_realloc(*ppos, rtotal + rret, rtotal);
		ft_memcpy(*ppos + rtotal, buff, rret);
		if ((newl = ft_strchr(*ppos + rtotal, (int)'\n')) != NULL)
			break ;
		rtotal += rret;
	}
	*line = ft_strndup(*ppos, newl - *ppos);
	return (1);
}

static int	cut_line(char **pos, char **line)
{
	char *newl;

	if ((newl = ft_strchr(*pos, (int)'\n')) != NULL)
	{
		*line = ft_strsub(*pos, 0, newl - *pos);
		ft_memmove(*pos, newl + 1, ft_strlen(newl));
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*pos = NULL;
	
	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (pos != NULL && cut_line(&pos, line))
		return (1);
	read_loop(fd, &pos, line);
	return (1);
}

#include "write_42.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	get_next_line(fd, &line);
	if (argc == 2)
		close(fd);
}