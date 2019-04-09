/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:01:51 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/09 22:43:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "read_42.h"
#include "memory_42.h"
#include "string_42.h"

static int	cut_line(char **pos, char **line)
{
	char *n_pos;

	if ((n_pos = ft_strchr(*pos, (int)'\n')))
	{
		*line = ft_strsub(*pos, 0, n_pos - *pos);
		*pos += n_pos - *pos + 1;
		return (1);
	}
	return (0);
}

static int	read_line(const int fd, char **pos, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	size_t old;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (*pos)
		{
			old = ft_strlen(*pos);
			ft_realloc(*pos, old + ft_strlen(buf), old);
			ft_memcpy(*pos + old, buf, ret);
		}
		else
			*pos = ft_strdup(buf);
		if (cut_line(pos, line))
			return (1);
	}
	*line = *pos;
	*pos = NULL;
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*pos = NULL;
	int			ret;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	if (pos && cut_line(&pos, line))
		return (1);
	if ((ret = read_line(fd, &pos, line)) != 0)
		return (ret);
	if (pos == NULL || pos[0] == '\0')
		return (0);
	*line = pos;
	pos = NULL;
	return (1);
}
