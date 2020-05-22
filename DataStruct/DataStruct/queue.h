#ifndef _QUEUE_H_
#define _QUEUE_H_

#include"common.h"
///////////////////////////////////////////////////////////////
//˳�����

#define SEQ_QUEUE_DEFAULT_SIZE 8
#define SEQ_QUEUE_INC_SIZE     3

typedef struct SeqQueue
{
	ElemType *base;
	int       capacity;
	int       front;
	int       rear;
}SeqQueue;

static bool SeqQueue_Inc(SeqQueue *psq);
void SeqQueueInit(SeqQueue *psq);
bool SeqQueueIsFull(SeqQueue *psq);
bool SeqQueueIsEmpty(SeqQueue *psq);
void SeqQueueEnque(SeqQueue *psq, ElemType x);
void SeqQueueDeque(SeqQueue *psq);
ElemType SeqQueueFront(SeqQueue *psq);
void SeqQueuePrint(SeqQueue *psq);

//����
static bool SeqQueue_Inc(SeqQueue *psq)
{
	ElemType *new_base = (ElemType*)realloc(psq->base, sizeof(ElemType)*(psq->capacity + SEQ_QUEUE_INC_SIZE));
	if (new_base == NULL)
		return false;
	psq->base = new_base;
	psq->capacity += SEQ_QUEUE_INC_SIZE;
	return true;
}

//˳�����г�ʼ��
void SeqQueueInit(SeqQueue *psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType)* SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}

bool SeqQueueIsFull(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}

bool SeqQueueIsEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

//���
void SeqQueueEnque(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq) && !SeqQueue_Inc(psq))
	{
		printf("��������������ʧ��, %d �������.\n", x);
		return;
	}
	psq->base[psq->rear++] = x;
}

//����
void SeqQueueDeque(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����ѿգ����ܳ���.\n");
		return;
	}

	psq->front++;
}

//��̽����Ԫ��
ElemType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����ѿգ�����ȡ��ͷԪ��.\n");
		return;
	}

	return psq->base[psq->front];
}


void SeqQueuePrint(SeqQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i<psq->rear; ++i)
		printf("%d ", psq->base[i]);
	printf("\n");
}

///////////////////////////////////////////////////////////////
//ѭ������
#define CIRCLE_QUEUE_DEFAULT_SIZE 8
#define CIRCLE_QUEUE_INC_SIZE 4

typedef struct CircleQueue
{
	ElemType *base;
	int       capacity;
	int       front;
	int       rear;
}CircleQueue;

void CircleQueueInit(CircleQueue *psq);
bool CircleQueueIsFull(CircleQueue *psq);
bool CircleQueueIsEmpty(CircleQueue *psq);
void CircleQueueEnque(CircleQueue *psq, ElemType x);
void CircleQueueDeque(CircleQueue *psq);
ElemType CircleQueueFront(CircleQueue *psq);
void CircleQueuePrint(CircleQueue *psq);

//����
static bool CircleQueue_Inc(CircleQueue *psq)
{
	ElemType *new_base = (ElemType*)realloc(psq->base, sizeof(ElemType)*(psq->capacity + CIRCLE_QUEUE_INC_SIZE));
	if (new_base == NULL)
		return false;
	psq->base = new_base;
	if (psq->front > psq->rear)
	{
		int temp = psq->rear;
		psq->rear = psq->capacity;
		for (int i = 0; i < temp; i++)
		{
			psq->base[psq->rear++] = psq->base[i];
		}
	}
	psq->capacity += CIRCLE_QUEUE_INC_SIZE;
	return true;
}

//��ʼ��
void CircleQueueInit(CircleQueue *psq)
{
	assert(psq != NULL);
	psq->base = (ElemType*)malloc(sizeof(ElemType)* (CIRCLE_QUEUE_DEFAULT_SIZE + 1));
	assert(psq->base != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE + 1;
	psq->front = psq->rear = 0;
}

bool CircleQueueIsFull(CircleQueue *psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}

bool CircleQueueIsEmpty(CircleQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

//���
void CircleQueueEnque(CircleQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (CircleQueueIsFull(psq) && !CircleQueue_Inc(psq))
	{
		printf("ѭ����������, %d �������.\n", x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}

//����
void CircleQueueDeque(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ����ܳ���.\n");
		return;
	}
	psq->front = (psq->front + 1) % psq->capacity;
}

//��ȡ����Ԫ��
ElemType CircleQueueFront(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ�����ȡ��ͷԪ��.\n");
		return;
	}

	return psq->base[psq->front];
}

void CircleQueuePrint(CircleQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ", psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
}

///////////////////////////////////////////////////////////////
//��ʽ����

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
void LinkQueueEnQue(LinkQueue *pq, ElemType x);
void LinkQueueDeQue(LinkQueue *pq);
void LinkQueuePrint(LinkQueue *pq);
bool LinkQueueEmpty(LinkQueue *pq);
ElemType LinkQueueFront(LinkQueue *pq);

//��ʼ��
void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

//���
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

//����
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

void LinkQueuePrint(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

bool LinkQueueEmpty(LinkQueue *pq)
{
	return pq->front == NULL;
}

//��ȡ����Ԫ��
ElemType LinkQueueFront(LinkQueue *pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
#endif /* _QUEUE_H_ */