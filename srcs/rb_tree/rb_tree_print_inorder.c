/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_print_inorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:46:37 by rpinoit           #+#    #+#             */
/*   Updated: 2019/04/11 17:01:19 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

void	rb_tree_print_inorder(t_rb_tree *node, void (*printer)(void *))
{
	if (node == NULL)
		return ;
	rb_tree_print_inorder(node->left, printer);
	printer(node->data);
	rb_tree_print_inorder(node->right, printer);
}
