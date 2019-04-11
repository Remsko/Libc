/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_hasredchild.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:10:50 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:00:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "rb_tree_42.h"

bool	rb_tree_hasredchild(t_rb_tree *node)
{
	return ((node->left != NULL && node->left->color == RED)
		|| (node->right != NULL && node->right->color == RED));
}
