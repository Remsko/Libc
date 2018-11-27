/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:56:27 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/27 10:58:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_42_H
# define STRING_42_H

#include <stddef.h>

size_t	ft_strlen(const char *str);
size_t	ft_strnlen(const char *str, size_t maxlen);

char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *s1, const char *s2, size_t n);

char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *s1, const char *s2, size_t n);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

#endif
