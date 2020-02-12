#include "rb_tree_42.h"
#include <assert.h>

void replace_node(t_rb_tree *n, t_rb_tree *child)
{
	child->parent = n->parent;
	if (n == n->parent->left)
		n->parent->left = child;
	else
		n->parent->right = child;
}

void delete_one_child(t_rb_tree *n, void (*del)(t_rb_tree *))
{
	t_rb_tree *child;

	child = (n->right == NULL) ? n->left : n->right;
	assert(child);
	replace_node(n, child);
	if (n->color == BLACK)
	{
		if (child->color == RED)
			child->color = BLACK;
		else
			delete_case_1(child);
	}
	del(n);
}