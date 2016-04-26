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
int count1(struct node *p)
{
	if (p == NULL)
		return(0);
	else
		if (p->left == NULL && p->right == NULL)
			return(1);
		else
			return(1 + (count1(p->left) + count1(p->right)));
}
void printLevel(struct node* root, int level, int *arr, int *index)
{

	if (root == NULL)
		return;
	if (level == 1)
	{
		arr[*index] = root->data;
		++*index;
	}
	else if (level > 1)
	{
		printLevel(root->right, level - 1, arr, index);
		printLevel(root->left, level - 1, arr, index);

	}
}
int height1(struct node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		
		int lheight = height1(node->left);
		int rheight = height1(node->right);
		if (lheight > rheight)
			return(lheight + 1);
		else return(rheight + 1);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
	return 0;
	int n = count1(root);
	int *array = (int*)malloc(sizeof(int)*n);
	int h = height1(root);
	int i, index = 0;
	for (i = 1; i <= h; i++)
		printLevel(root, i, array, &index);
	return array;
}
