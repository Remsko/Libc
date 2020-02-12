#include "rb_tree_42.h"

void insert_case_1(t_rb_tree *n)
{
	n->color = BLACK;
}

void insert_case_2(t_rb_tree *n)
{
	(void)n;
	return;
}

void insert_case_3(t_rb_tree *n)
{
	get_parent(n)->color = BLACK;
	get_uncle(n)->color = BLACK;
	get_grand_parent(n)->color = RED;
	insert_repair_tree(get_grand_parent(n));
}

static void insert_case_4_step_2(t_rb_tree *n)
{
	t_rb_tree *p;
	t_rb_tree *g;

	p = get_parent(n);
	g = get_grand_parent(n);
	if (n == p->left)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = BLACK;
	g->color = RED;
}

void insert_case_4(t_rb_tree *n)
{
	t_rb_tree *p;
	t_rb_tree *g;

	p = get_parent(n);
	g = get_grand_parent(n);
	if (n == p->right && p == g->left)
	{
		rotate_left(p);
		n = n->left;
	}
	else if (n == p->left && p == g->right)
	{
		rotate_right(p);
		n = n->right;
	}

	insert_case_4_step_2(n);
}