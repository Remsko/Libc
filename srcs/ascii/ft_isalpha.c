/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:17:28 by rpinoit           #+#    #+#             */
/*   Updated: 2018/11/25 18:25:52 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha(int c)
{
	return ((c | 32) >= 'a' && (c | 32) <= 'z');
}