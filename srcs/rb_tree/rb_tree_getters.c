#include "rb_tree_42.h"

t_rb_tree *get_parent(t_rb_tree *n)
{
	if (n == NULL)
		return NULL;
	return n->parent;
}

t_rb_tree *get_grand_parent(t_rb_tree *n)
{
	return get_parent(get_parent(n));
}

t_rb_tree *get_sibling(t_rb_tree *n)
{
	t_rb_tree *p;

	p = get_parent(n);
	if (p == NULL)
		return NULL;
	if (n == p->left)
		return p->right;
	else
		return p->left;
}

t_rb_tree *get_uncle(t_rb_tree *n)
{
	t_rb_tree *p;

	p = get_parent(n);
	return get_sibling(p);
}