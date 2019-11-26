#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void TR_init(TREE_PTR *root){
	*root=NULL;
}

int TR_empty(TREE_PTR root){
	return root==NULL; 
}

elem TR_data(TREE_PTR p){
	return p->data;
}

int TR_insert_root(TREE_PTR *root,elem x){
	TREE_PTR newnode;
	if(*root!=NULL){
		return FALSE;
	}
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(!newnode){
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	*root=newnode;
}
int TR_insert_right(TREE_PTR node,elem x){
	TREE_PTR newnode;
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(node->right!=NULL)
		return FALSE;
	if(!newnode){
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	node->right=newnode;
}
int TR_insert_left(TREE_PTR node,elem x){
	TREE_PTR newnode;
	newnode=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	if(node->left!=NULL)
		return FALSE;
	if(!newnode){
		return FALSE;
	}
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	node->left=newnode;
}
int TR_delete_root(TREE_PTR *root,elem *x){
	if((*root)->left!=NULL  || (*root)->right!=NULL){
		return FALSE;
	}
	*x=(*root)->data;
	free(*root);
	*root=NULL;
	return TRUE;
}

int TR_delete_right(TREE_PTR parent,elem *x){
	TREE_PTR current;
	if(parent->right==NULL){
		return FALSE;
	}
	current=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	current=parent->right;
	if(current->left!=NULL || current->right!=NULL)
		return FALSE;
	*x=current->data;
	free(current);
	parent->right=NULL;
	return TRUE;
}

int TR_delete_left(TREE_PTR parent,elem *x){
	TREE_PTR current;
	if(parent->left==NULL){
		return FALSE;
	}
	current=(TREE_NODE *)malloc(sizeof(TREE_NODE));
	current=parent->left;
	if(current->left!=NULL || current->right!=NULL)
		return FALSE;
	*x=current->data;
	free(current);
	parent->left=NULL;
	return TRUE;
}

void TR_preorder(TREE_PTR v){
	if(v!=NULL){
		TR_print_node(v);
		TR_preorder(v->left);
		TR_preorder(v->right);
	}
}

void TR_inorder(TREE_PTR v){
	if(v!=NULL){
		TR_inorder(v->left);
		TR_print_node(v);
		TR_inorder(v->right);
	}
}

void TR_postorder(TREE_PTR v){
	if(v!=NULL){
		TR_postorder(v->left);
		TR_postorder(v->right);
		TR_print_node(v);		
	}
}

void TR_print_node(TREE_PTR v){
	printf("%d ",v->data); 
}


int TR_search_BST(TREE_PTR root,elem x){
	TREE_PTR current;
	current=root;
	while(current!=NULL){
		if (x==current->data){
			return TRUE;
		}else if(x<current->data){
			current=current->left;
			}else{
				current=current->right;
			}
		}
		return FALSE;
	}




