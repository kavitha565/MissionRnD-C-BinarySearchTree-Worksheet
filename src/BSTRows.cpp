/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int count(struct node *p)
{
	if (p == NULL)
		return(0);
	else
		if (p->left == NULL && p->right == NULL)
			return(1);
		else
			return(1 + (count(p->left) + count(p->right)));
}
int arr(struct node *root, int i, int array[])
{

	if (root == NULL)
		return i;


	array[i] = root->data;
	i++;
	if (root->right != NULL)
		arr(root->right, i, array);
	if (root->left != NULL)
		arr(root->left, i, array);
	


	array[i] = root->data;
	i++;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
    return NULL;
	int i = 0;
	int n = count(root);
	int *array = (int*)malloc(sizeof(int)*n);
	arr(root, i, array);

}
