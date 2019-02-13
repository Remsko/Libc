#include "incs/rb_tree_42.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cmp(void *s1, void *s2)
{
	return ((int)s1 - (int)s2);
}

void print(void *data)
{
	printf("%d ", (int)data);
}

int main(void)
{
	t_rb_tree *root; 

	root = NULL;
	rb_tree_insert(&root, (void *)7, &cmp); 
	
	rb_tree_insert(&root, (void *)5, &cmp); 
	
	rb_tree_insert(&root, (void *)25, &cmp); 
	
	rb_tree_insert(&root, (void *)1, &cmp); 
	
	rb_tree_insert(&root, (void *)-2, &cmp); 
	
	rb_tree_insert(&root, (void *)36, &cmp); 
	
	rb_tree_insert(&root, (void *)15, &cmp); 
	
	rb_tree_insert(&root, (void *)35, &cmp); 
	
	rb_tree_insert(&root, (void *)34, &cmp); 
	
	rb_tree_insert(&root, (void *)37, &cmp); 
	
	rb_tree_insert(&root, (void *)50, &cmp); 
	
	rb_tree_insert(&root, (void *)0, &cmp); 
	//rb_tree_print_inorder(root, &print);


	rb_tree_delete(root);
	return (0);
}
