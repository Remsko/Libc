/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:37:01 by rpinoit           #+#    #+#             */
/*   Updated: 2018/10/29 20:56:25 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>

# define MEM_WORD_LEN sizeof(unsigned long int)
# define MEM_BLOCK_SIZE (8 * MEM_WORD_LEN)

#endif