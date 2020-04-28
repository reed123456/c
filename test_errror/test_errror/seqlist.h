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
static bool _Inc(SeqList *pst);

void SeqListInIt(SeqList *pst);
bool IsFull(SeqList *pst);
bool IsEmpty(SeqList *pst);
void SeqListPushBack(SeqList *pst, ElemType x);
void SeqListPushFront(SeqList *pst, ElemType x);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);

void SeqListInsertByPos(SeqList *pst, int pos, ElemType x);
void SeqListInsertByVal(SeqList *pst, ElemType x);
void SeqListIDeleteByPos(SeqList *pst, int pos);
void SeqListIDeleteByVal(SeqList *pst, ElemType key);
void SeqListRemoveAll(SeqList *pst, ElemType key);
void SeqListSort(SeqList *pst);
int SeqListFind(SeqList *pst, ElemType key);
void SeqListReverse(SeqList *pst);

size_t SeqListLength(SeqList *pst);
size_t SeqListCapacity(SeqList *pst);
void SeqListClear(SeqList *pst);
void SeqListShow(SeqList *pst);
void SeqListDestroy(SeqList *pst);

///////////////////////////////////////////////////
//�����ӿ�ʵ��

//����
static bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*pst->capacity * 2);
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}


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

	if (IsFull(pst) && !_Inc(pst)) //��·��ֵ
	{
		//�ռ����˲����ݲ��ɹ�
		printf("˳���ռ�����,���ܲ������� %d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

//β������Ԫ��
void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳������������ܲ�������:%d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

//β��ɾ��Ԫ��
void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	pst->size--;
}

//ͷ��ɾ��Ԫ��
void SeqListPopFront(SeqList *pst)
{

	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ����ܴ�β��ɾ��Ԫ��...\n");
		return 0;
	}
	for (int i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//��λ�ò���
void SeqListInsertByPos(SeqList *pst, int pos, ElemType x)
{
	assert(pst != NULL);
	if (pos < 0 || pos >pst->size)
	{
		printf("�����λ�÷Ƿ������� %d ���ܱ�����...\n", x);
		return 0;
	}
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳������������ܰ�λ�ò�������:%d\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

//��ֵ����
void SeqListInsertByVal(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("˳������������ܰ�ֵ��������:%d\n", x);
		return;
	}
	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}

//��λ��ɾ��
void SeqListIDeleteByPos(SeqList *pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�λֵɾ������...\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("Ҫɾ����λ�÷Ƿ������ܰ�λֵɾ������...\n");
		return 0;
	}
	for (int i = pos; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//��ֵɾ��
void SeqListIDeleteByVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�ֵɾ������...\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ����ֵ������...\n");
		return;
	}
	else
	{
		SeqListIDeleteByPos(pst, pos);
	}
}

//ɾ������ƥ���Ԫ��
void SeqListRemoveAll(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳����ѿգ����ܰ�ֵɾ������...\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ����ֵ������...\n");
		return;
	}
	while (SeqListFind(pst, key) != -1)
	{
		SeqListIDeleteByPos(pst, pos);
	}
}

//����
void SeqListSort(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size <= 1)
		return;
	for (int i = 0; i < pst->size - 1; i++)
	{
		for (int j = 0; j < pst->size - i - 1; j++)
		{
			if (pst->base[j] > pst->base[j + 1])
			{
				ElemType temp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = temp;
			}
		}
	}
}

//����
int SeqListFind(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	for (int i = 0; i < pst->size; ++i)
	{
		if (pst->base[i] == key)
		{
			return i;
		}
	}
	return -1;
}

//ת��˳���
void SeqListReverse(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size <= 1)
		return;

	int left = 0;
	int right = pst->size - 1;
	while (left < right)
	{
		Swap(&pst->base[left], &pst->base[right]);
		left++;
		right--;
	}
}

size_t SeqListLength(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size;
}

size_t SeqListCapacity(SeqList *pst)
{
	assert(pst != NULL);
	return pst->capacity / sizeof(ElemType);
}

//������Ա�
void SeqListClear(SeqList *pst)
{
	assert(pst != NULL);
	pst->size = 0;
}

//��ʾSeqList������
void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ��...\n");
		return 0;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

//�ݻ�pst->base
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