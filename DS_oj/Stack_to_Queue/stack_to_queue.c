#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
//Á´Õ»
typedef char ElemType;
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link; //next
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode *top;
}LinkStack;

void LinkStackInit(LinkStack *pst);
bool LinkStackEmpty(LinkStack *pst);
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);

void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

bool LinkStackEmpty(LinkStack *pst)
{
	return pst->top == NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;

	free(p);
}
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	return pst->top->data;
}

void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	while (pst->top != NULL)
	{
		LinkStackNode *p = pst->top;
		pst->top = p->link;
		free(p);
	}
}

//////////////////////////////////////////////////////////////
typedef struct
{
	LinkStack instack;
	LinkStack outstack;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
	LinkStackInit(&(pq->instack));
	LinkStackInit(&(pq->outstack));
	return pq;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	LinkStackPush(&(obj->instack), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	if (LinkStackEmpty(&(obj->outstack)))
	{
		while (!LinkStackEmpty(&(obj->instack)))
		{
			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
			LinkStackPop(&(obj->instack));
		}
	}
	ElemType val = LinkStackTop(&(obj->outstack));
	LinkStackPop(&(obj->outstack));
	return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (LinkStackEmpty(&(obj->outstack)))
	{
		while (!LinkStackEmpty(&(obj->instack)))
		{
			LinkStackPush(&(obj->outstack), LinkStackTop(&(obj->instack)));
			LinkStackPop(&(obj->instack));
		}
	}

	ElemType val = LinkStackTop(&(obj->outstack));
	return val;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return LinkStackEmpty(&(obj->instack)) && LinkStackEmpty(&(obj->outstack));
}

void myQueueFree(MyQueue* obj)
{
	LinkStackDestroy(&(obj->instack));
	LinkStackDestroy(&(obj->outstack));
	free(obj);
}
