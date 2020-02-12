/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:56:14 by rpinoit           #+#    #+#             */
/*   Updated: 2020/02/12 16:34:03 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_42_H
#define RB_TREE_42_H

#include <stddef.h>
#include <stdbool.h>

enum e_rb_color
{
	RED = 0,
	BLACK = 1
};

typedef struct s_rb_tree
{
	struct s_rb_tree *left;
	struct s_rb_tree *right;
	struct s_rb_tree *parent;
	void *data;
	enum e_rb_color color;
} t_rb_tree;

t_rb_tree *get_parent(t_rb_tree *n);
t_rb_tree *get_grand_parent(t_rb_tree *n);
t_rb_tree *get_sibling(t_rb_tree *n);
t_rb_tree *get_uncle(t_rb_tree *n);

void rotate_left(t_rb_tree *n);
void rotate_right(t_rb_tree *n);

t_rb_tree *insert(t_rb_tree *root, t_rb_tree *n, int (*cmp)(t_rb_tree *, t_rb_tree *));
void insert_recurse(t_rb_tree *root, t_rb_tree *n, int (*cmp)(t_rb_tree *, t_rb_tree *));
void insert_repair_tree(t_rb_tree *node);

void insert_case_1(t_rb_tree *n);
void insert_case_2(t_rb_tree *n);
void insert_case_3(t_rb_tree *n);
void insert_case_4(t_rb_tree *n);

void replace_node(t_rb_tree *n, t_rb_tree *child);
void delete_one_child(t_rb_tree *n, void (*del)(t_rb_tree *));

void delete_case_1(t_rb_tree *n);
void delete_case_2(t_rb_tree *n);
void delete_case_3(t_rb_tree *n);
void delete_case_4(t_rb_tree *n);
void delete_case_5(t_rb_tree *n);
void delete_case_6(t_rb_tree *n);

#endif
