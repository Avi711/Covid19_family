/****************
* Avraham sikirov
* 318731478
* 01
* ex6
***************/

#include <stdio.h>
#include "Utils.h"
#include "ex6.h"
#include "queue.h";
#define COUNT 8

// Function to print Trinary tree in 2D 
// It does reverse inorder traversal 
void print2DUtil(Trin_Ari* root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%s %d\n", root->name, root->id);
	// Process middle child 
	print2DUtil(root->middle, space);
	printf("\n");
	// Process left child 
	print2DUtil(root->left, space);
}

/******************
* Function Name: printPreOrder
* Input: pointer to the root
* Output: Prints the tree in pre order. 
* Function Operation: The function goes through the whole
* tree with the help of recursion and prints pre order.
******************/

void printPreOrder(Trin_Ari* root)
{
	if (root == NULL)
		return;
	printf("%s ID: %d\n",root->name, root->id);
	printPreOrder(root->left);
	printPreOrder(root->middle);
	printPreOrder(root->right);
}

/******************
* Function Name: printLeftOrder
* Input: pointer to the root
* Output: Prints the tree in left order.
* Function Operation: The function goes through the whole
* tree with the help of recursion and prints left order.
******************/

void printLeftOrder(Trin_Ari* root)
{
	if (root == NULL)
		return;
	printLeftOrder(root->left);
	printf("%s ID: %d\n", root->name, root->id);
	printLeftOrder(root->middle);
	printLeftOrder(root->right);
}
 
/******************
* Function Name: BFS
* Input: pointer to the root, initial string to print before every print. 
* Output: Prints the tree is BFS order. 
* Function Operation: The function uses the queue,
* in order to print all the tree in BFS
******************/

void BFS(Trin_Ari* root, char* string)
{
	// check if there is a tree.
	if (root == NULL)
	{
		return;
	}
	// create a queue and enter to it the root. 
	Queue* q = createQueue();
	enQueue(q, root);


	// goes over the tree is the queue and prints is BFS order. 
	while (isEmpty(q))
	{
		Trin_Ari* current = (Trin_Ari*)q->front->key;
				
		printf("%s%s %d\n",string, current->name, current->id);
		deQueue(q);
		if (current->left != NULL)
		{
			enQueue(q, current->left);
		}
		if (current->middle != NULL)
		{
			enQueue(q, current->middle);
		}
		if (current->right != NULL)
		{
			enQueue(q, current->right);
		}
	}
	destroyQueue(q);
}

