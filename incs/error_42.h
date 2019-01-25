/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_42.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:46:25 by rpinoit           #+#    #+#             */
/*   Updated: 2018/12/22 17:45:36 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_42_H
#define ERROR_42_H

#include <stdbool.h>
#include <stddef.h>

typedef unsigned char t_status;

typedef struct      s_error
{
    char            *msg;
    char            *debug;
    t_status        status;
}                   t_error;

void    error_malloc(char *where);
t_error *error_create(char *msg, char *debug, unsigned char status);
void    error_throw(t_error *err, void (*strfy)(t_status), bool debug_mode);
void    malloc_or_die(void **ptr, size_t size, char *where);

#endif