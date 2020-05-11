#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef struct
{
	int *base;
	int  capacity;
	int  front;
	int  rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue *pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->base = (int*)malloc(sizeof(int)* (k + 1));
	pcq->capacity = k + 1;
	pcq->front = pcq->rear = 0;
	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if ((obj->rear + 1) % obj->capacity == obj->front)
		return false;
	obj->base[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->capacity;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (obj->front == obj->rear)
		return false;
	obj->front = (obj->front + 1) % obj->capacity;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->base[(obj->rear - 1 + obj->capacity) % obj->capacity];
	//return obj->base[obj->rear-1];  
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % obj->capacity == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->base);
	free(obj);
}

int main()
{
	return 0;
}