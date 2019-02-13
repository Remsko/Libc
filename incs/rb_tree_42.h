/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:56:14 by rpinoit           #+#    #+#             */
/*   Updated: 2019/02/12 13:30:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_42_H
#define RB_TREE_42_H

#include <stdbool.h>

typedef enum e_rb_color
{
    RED = 0,
    BLACK = 1
} t_rb_color;

typedef struct s_rb_tree
{
    struct s_rb_tree *left;
    struct s_rb_tree *right;
    struct s_rb_tree *parent;
    void *data;
    t_rb_color color;
} t_rb_tree;

t_rb_tree *rb_tree_new_node(void *data);

bool rb_tree_isonleft(t_rb_tree *node);

t_rb_tree *rb_tree_uncle(t_rb_tree *node);

t_rb_tree *rb_tree_sibling(t_rb_tree *node);

bool rb_tree_hasredchild(t_rb_tree *node);

void    rb_tree_move_down(t_rb_tree *node, t_rb_tree *nparent);

void rb_tree_left_rotate(t_rb_tree **root, t_rb_tree *node);

void rb_tree_right_rotate(t_rb_tree **root, t_rb_tree *node);

#endif