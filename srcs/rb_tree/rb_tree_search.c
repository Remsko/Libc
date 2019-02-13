/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:29:12 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/13 14:04:02 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rb_tree_42.h"

t_rb_tree *rb_tree_search(t_rb_tree *root, void *data, int (*cmp_f)(void *, void *))
{
    t_rb_tree *tmp;
    int diff;

    tmp = root;
    while (tmp != NULL)
    {
        diff = cmp_f(data, tmp->data);
        if (diff < 0)
        {
            if (tmp->left == NULL)
                break ;
            else
                tmp = tmp->left;
        }
        else if (diff == 0)
            break ;
        else
        {
            if (tmp->right == NULL)
                break ;
            else
                tmp = tmp->right;
        }
    }
    return (tmp);
}