#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"
#define SEQLIST_DEFAULT_SIZE 8

//����˳���ṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

///////////////////////////////////////////////////
//���������ӿ�
void SeqListInIt(SeqList *pst);
bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListPushBack(SeqList *pst, ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListShow(SeqList *pst);
void SeqListDestroy(SeqList *pst);

///////////////////////////////////////////////////
//�����ӿ�ʵ��

//��ʼ��SeqList
void SeqListInIt(SeqList *pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = sizeof(ElemType)*SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}


bool IsFull(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;
}

bool IsEmpty(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size == 0;
}

//ͷ������Ԫ��
void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳������������ܲ�������:%d\n", x);
		return;
	}

	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos-1];
	}
	pst->base[0] = x;
	pst->size++;
}

//β������Ԫ��
void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳������������ܲ�������:%d\n", x);
		return;
	}

	pst->base[pst->size++] = x;
}

//��ʾSeqList������
void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}


void SeqListDestroy(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->base != NULL)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = 0;
	pst->size = 0;
}

#endif /*_SEQLIST_H_*/