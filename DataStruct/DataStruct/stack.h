#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

///////////////////////////////////////////////////////////////
//˳��ջ
//˳��ջ�����ݽ���ͬѧ���������

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3

typedef struct SeqStack
{
	ElemType *base;
	size_t    capacity;
	int       top;
}SeqStack;

static bool SeqStack_Inc(SeqStack *pst);
void SeqStackInit(SeqStack *pst);
bool SeqStackIsFull(SeqStack *pst);
bool SeqStackIsEmpty(SeqStack *pst);
void SeqStackPush(SeqStack *pst, ElemType x);
void SeqStackPop(SeqStack *pst);
ElemType SeqStackTop(SeqStack *pst); // SeqStackPeek();
void SeqStackPrint(SeqStack *pst);
void SeqStackDestroy(SeqStack *pst);

//����
static bool SeqStack_Inc(SeqStack *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity + SEQ_STACK_INC_SIZE));
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity += SEQ_STACK_INC_SIZE;
	return true;
}

//��ʼ��
void SeqStackInit(SeqStack *pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}

bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}

bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

//��ջ
void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst) && !SeqStack_Inc(pst))
	{
		printf("ջ�ռ�������������ʧ�ܣ�%d ������ջ.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

//��ջ
void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

//��̽ջ��Ԫ��
ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ�����ȡջ��Ԫ��.\n");
		return;
	}

	return pst->base[pst->top - 1];
}

void SeqStackPrint(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("%d\n", pst->base[i]);
	printf("\n");
}

//�ݻ�ջ
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

///////////////////////////////////////////////////////////////
//��ջ
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
void LinkStackPush(LinkStack *pst, ElemType x);
void LinkStackPop(LinkStack *pst);
ElemType LinkStackTop(LinkStack *pst);
void LinkStackPrint(LinkStack *pst);
void LinkStackDestroy(LinkStack *pst);

//��ʼ��
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

//��ջ
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	node->link = pst->top;
	pst->top = node;
}

//��ջ
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;

	free(p);
}

//��̽ջ��Ԫ��
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	return pst->top->data;
}

void LinkStackPrint(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->link;
	}
	printf("\n");
}

//�ݻ�
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

#endif /* _STACK_H_ */