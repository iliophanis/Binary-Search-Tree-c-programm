#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	TREE_PTR root;
	int elem;
	
	TR_init(&root);
	
	TR_insert_root(&root,10);
	
	TR_insert_left(root,2);
	TR_insert_right(root,5);
	TR_insert_left(root->left,6);
	TR_insert_right(root->left,7);
	TR_insert_left(root->right,8);
	printf("Inorder");
	TR_inorder(root);
	printf("\nPreorder");
	TR_preorder(root);
	printf("\nPostOrder");
	TR_postorder(root);
	elem=TR_search_BST(root,8);
	if (elem==1){
		printf("\nTrue");
	}		
	else{
		printf("\nFalse");
	}
	return 0;
}
