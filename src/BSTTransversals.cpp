/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void getinorder(struct node *root, int *arr, int *index){
	if (root != NULL)
	{
		getinorder(root->left, arr, index);
		arr[*index] = root->data;
		++*index;
		getinorder(root->right, arr, index);
	}

}

void getpreorder(struct node *root, int *arr, int *index){
	if (root != NULL)
	{
		arr[*index] = root->data;
		++*index;
		getpreorder(root->left, arr, index);
		getpreorder(root->right, arr, index);
	}

}

void getpostorder(struct node *root, int *arr, int *index){
	if (root != NULL)
	{
		getpostorder(root->left, arr, index);
		getpostorder(root->right, arr, index);
		arr[*index] = root->data;
		++*index;
	}

}

void inorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL)
		return ;
	
		int i = 0;
		getinorder(root, arr, &i);
	
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

		int i = 0;
		getpreorder(root, arr, &i);
	
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;

		int i = 0;
		getpostorder(root, arr, &i);
	
}