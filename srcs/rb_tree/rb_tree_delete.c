/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:09:22 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 15:21:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rb_tree_42.h"

void rb_tree_delete(t_rb_tree *node)
{
    if (node == NULL)
        return ;
    rb_tree_delete(node->left);
    rb_tree_delete(node->right);
    free(node);
}