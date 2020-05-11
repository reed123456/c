#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef int ElemType;

typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
ElemType LinkQueueFront(LinkQueue *pq);
ElemType LinkQueueBack(LinkQueue *pq);
void LinkQueueEnQue(LinkQueue *pq, ElemType x);
void LinkQueueDeQue(LinkQueue *pq);
void LinkQueueDestroy(LinkQueue *pq);

void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

bool LinkQueueEmpty(LinkQueue *pq)
{
	assert(pq != NULL);
	return pq->front == NULL;
}

ElemType LinkQueueFront(LinkQueue *pq)
{
	return pq->front->data;
}
ElemType LinkQueueBack(LinkQueue *pq)
{
	return pq->rear->data;
}

void LinkQueueEnQue(LinkQueue *pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;

	if (pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode *p = pq->front;
		pq->front = p->link;
		free(p);
	}
}

void LinkQueueDestroy(LinkQueue *pq)
{
	LinkQueueNode *p = pq->front;
	while (p != NULL)
	{
		pq->front = p->link;
		free(p);
		p = pq->front;
	}
	pq->front = pq->rear = NULL;
}


////////////////////////////////////////////////////////////////////////
typedef struct
{
	LinkQueue q1;
	LinkQueue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack *pst = (MyStack*)malloc(sizeof(MyStack));
	LinkQueueInit(&(pst->q1));
	LinkQueueInit(&(pst->q2));
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	LinkQueue *pnoempty;
	if (LinkQueueEmpty(&(obj->q1)))
		pnoempty = &(obj->q2);
	else
		pnoempty = &(obj->q1);
	LinkQueueEnQue(pnoempty, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	LinkQueue *pempty, *pnoempty;
	if (LinkQueueEmpty(&(obj->q1)))
	{
		pempty = &(obj->q1);
		pnoempty = &(obj->q2);
	}
	else
	{
		pempty = &(obj->q2);
		pnoempty = &(obj->q1);
	}

	ElemType val;
	while (!LinkQueueEmpty(pnoempty))
	{
		val = LinkQueueFront(pnoempty);
		LinkQueueDeQue(pnoempty);
		if (LinkQueueEmpty(pnoempty))
			break;
		LinkQueueEnQue(pempty, val);
	}
	return val;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	LinkQueue *pnoempty;
	if (LinkQueueEmpty(&(obj->q1)))
		pnoempty = &(obj->q2);
	else
		pnoempty = &(obj->q1);
	return LinkQueueBack(pnoempty);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	return LinkQueueEmpty(&(obj->q1)) && LinkQueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj)
{
	LinkQueueDestroy(&(obj->q1));
	LinkQueueDestroy(&(obj->q2));
	free(obj);
}