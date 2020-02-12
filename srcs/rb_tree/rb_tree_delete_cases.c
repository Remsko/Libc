#include "rb_tree_42.h"

void delete_case_1(t_rb_tree *n)
{
	if (n->parent != NULL)
		delete_case_2(n);
}

void delete_case_2(t_rb_tree *n)
{
	t_rb_tree *s;

	s = get_sibling(n);
	if (s->color == RED)
	{
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left)
			rotate_left(n->parent);
		else
			rotate_right(n->parent);
	}
	delete_case_3(n);
}

void delete_case_3(t_rb_tree *n)
{
	t_rb_tree *s;

	s = get_sibling(n);
	if ((n->parent->color == BLACK) && (s->color == BLACK) &&
		(s->left->color == BLACK) && (s->right->color == BLACK))
	{
		s->color = RED;
		delete_case_1(n->parent);
	}
	else
		delete_case_4(n);
}

void delete_case_4(t_rb_tree *n)
{
	t_rb_tree *s;

	s = get_sibling(n);
	if ((n->parent->color == RED) && (s->color == BLACK) &&
		(s->left->color == BLACK) && (s->right->color == BLACK))
	{
		s->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case_5(n);
}

void delete_case_5(t_rb_tree *n)
{
	t_rb_tree *s;

	s = get_sibling(n);
	if (s->color == BLACK)
	{
		if ((n == n->parent->left) && (s->right->color == BLACK) &&
			(s->left->color == RED))
		{
			s->color = RED;
			s->left->color = BLACK;
			rotate_right(s);
		}
		else if ((n == n->parent->right) && (s->left->color == BLACK) &&
				 (s->right->color == RED))
		{
			s->color = RED;
			s->right->color = BLACK;
			rotate_left(s);
		}
	}
	delete_case_6(n);
}

void delete_case_6(t_rb_tree *n)
{
	t_rb_tree *s;

	s = get_sibling(n);
	s->color = n->parent->color;
	n->parent->color = BLACK;

	if (n == n->parent->left)
	{
		s->right->color = BLACK;
		rotate_left(n->parent);
	}
	else
	{
		s->left->color = BLACK;
		rotate_right(n->parent);
	}
}