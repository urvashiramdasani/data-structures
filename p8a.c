// program to implement avl tree

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *right;
	struct node *left;
	//int height;
};

struct node *root = NULL;

struct node * createNode(int val) {
	struct node *n = (struct node *) malloc(sizeof(struct node));
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	//n->height = 1;
	return n;
}

int height_tree(struct node*root) {
	if(root == NULL) {
		return 0;
	}
	int left_height = height_tree(root->left);
	int right_height = height_tree(root->right);
	if(left_height>right_height) return left_height+1;
	else right_height+1;
}

struct node* insert(struct node*root,int val) {
	if(root == NULL) {
		root = createNode(val);
		return root;
	}
	if(val>root->data) {
		root->right = insert(root->right,val);
	}
	else if(val<root->data) {
		root->left = insert(root->left,val);
	}
	else{
		printf("\nInvalid Data.!!");
		return root;
	}
	
}