#include "rb_tree_42.h"

t_rb_tree *insert(t_rb_tree *root, t_rb_tree *n, int (*cmp)(t_rb_tree *, t_rb_tree *))
{
	insert_recurse(root, n, cmp);
	insert_repair_tree(n);
	root = n;
	while (get_parent(root) != NULL)
		root = get_parent(root);
	return root;
}

void insert_recurse(t_rb_tree *root, t_rb_tree *n, int (*cmp)(t_rb_tree *, t_rb_tree *))
{
	if (root != NULL)
	{
		if (cmp(n, root) > 0)
		{
			if (root->left != NULL)
				return insert_recurse(root->left, n, cmp);
			else
				root->left = n;
		}
		else
		{
			if (root->right != NULL)
				return insert_recurse(root->right, n, cmp);
			else
				root->right = n;
		}
	}
	n->parent = root;
	n->left = NULL;
	n->right = NULL;
	n->color = RED;
}

void insert_repair_tree(t_rb_tree *n)
{
	if (get_parent(n) == NULL)
	{
		insert_case_1(n);
	}
	else if (get_parent(n)->color == BLACK)
	{
		insert_case_2(n);
	}
	else if (get_uncle(n) != NULL && get_uncle(n)->color == RED)
	{
		insert_case_3(n);
	}
	else
	{
		insert_case_4(n);
	}
}