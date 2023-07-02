/****************
* Avraham sikirov
* 318731478
* 01
* ex6
***************/

#include "ex6.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "queue.h"

/******************
* Function Name: createQueue
* Input: 
* Output: pointer to the first node of the queue.
* Function Operation: creating new node using malloc and assigning its head and tail to null
* and then returning pointer to it.
******************/

Queue* createQueue()
{
	Queue* q = malloc(sizeof(Queue));
		if (q == NULL)
		{
			return;
		}
		q->front = NULL;
		q->rear = NULL;

		return q;

}

/******************
* Function Name: enQueue
* Input: pointer to the queue and generic pointer.
* Output: 0,1 (true of false) 
* Function Operation: creating new node using malloc and assigning it the the next place 
* in the queue 
******************/

int enQueue(Queue* q, void* k)
{
	// create new node
	QNode* newNode = malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		return FALSE;
	}
	newNode->key = k;
	newNode->next = NULL;

	//if there is node in the rear, connect this node to the new ndoe.
	if (q->rear != NULL)
	{
		q->rear->next = newNode;
	}
	q->rear = newNode;
	if (q->front == NULL)
	{
		q->front = newNode;
	}
	return TRUE;
}

/******************
* Function Name: deQueue
* Input: pointer to the queue 
* Output: 
* Function Operation: Removing the last node from the queue and freeing it. 
******************/

void deQueue(Queue* q)
{
	QNode* temp = q->front;
	int result = temp->key;
	q->front = q->front->next;
	if (q->front == NULL)
	{
		q->rear = NULL;
	}
	free(temp);
	return;
}

/******************
* Function Name: isEmpty
* Input: pointer to the queue
* Output: 0,1 (true or false) 
* Function Operation: checking if there is an exist queue. 
******************/

int isEmpty(Queue* q)
{
	if (q->front == NULL)
	{
		return FALSE;
	}
	return TRUE;
}

/******************
* Function Name: destroyQueue
* Input: pointer to the queue
* Output: 
* Function Operation: going over the queue deleting the nodes using "Free"
******************/

void destroyQueue(Queue* q)
{
	/*Queue* temp;
	while (q->front != NULL)
	{
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}*/

	free(q);
}