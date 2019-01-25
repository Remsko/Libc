/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:06:41 by rpinoit           #+#    #+#             */
/*   Updated: 2019/01/25 17:09:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "string_42.h"
#include "read_42.h"

char    *read_file(int fd)
{
    char    buf[BUFF_SIZE + 1];
    char    *str;
    char    *tmp;
    int     ret;

    str = NULL;
    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[ret] = '\0';
        if (str != NULL)
        {
            tmp = ft_strdup(str);
            free(str);
            str = ft_strjoin(tmp, buf);
            free(tmp);
        }
        else
            str = ft_strdup(buf);
    }
    if (ret == -1)
        free(str);
    return (str);
}