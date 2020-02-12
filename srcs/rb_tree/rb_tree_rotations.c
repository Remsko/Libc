#include "rb_tree_42.h"
#include <assert.h>

void rotate_left(t_rb_tree *n)
{
	t_rb_tree *nnew;
	t_rb_tree *p;

	nnew = n->right;
	p = get_parent(n);
	assert(nnew != NULL);
	n->right = nnew->left;
	nnew->left = n;
	n->parent = nnew;
	if (n->right != NULL)
		n->right->parent = n;
	if (p != NULL)
	{
		if (n == p->left)
			p->left = nnew;
		else if (n == p->right)
			p->right = nnew;
	}
	nnew->parent = p;
}

void rotate_right(t_rb_tree *n)
{
	t_rb_tree *nnew;
	t_rb_tree *p;

	nnew = n->left;
	p = get_parent(n);
	assert(nnew != NULL);
	n->left = nnew->right;
	nnew->right = n;
	n->parent = nnew;
	if (n->left != NULL)
		n->left->parent = n;
	if (p != NULL)
	{
		if (n == p->left)
			p->left = nnew;
		else if (n == p->right)
			p->right = nnew;
	}
	nnew->parent = p;
}