#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"
#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

///////////////////////////////////////////////////
//声明函数接口
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
//函数接口实现

//扩容
static bool _Inc(SeqList *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*pst->capacity * 2);
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity *= 2;
	return true;
}


//初始化SeqList
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

//头部插入元素
void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);

	if (IsFull(pst) && !_Inc(pst)) //短路求值
	{
		//空间满了并扩容不成功
		printf("顺序表空间已满,不能插入数据 %d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

//尾部插入元素
void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不能插入数据:%d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

//尾部删除元素
void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	pst->size--;
}

//头部删除元素
void SeqListPopFront(SeqList *pst)
{

	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能从尾部删除元素...\n");
		return 0;
	}
	for (int i = 0; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//按位置插入
void SeqListInsertByPos(SeqList *pst, int pos, ElemType x)
{
	assert(pst != NULL);
	if (pos < 0 || pos >pst->size)
	{
		printf("插入的位置非法，数据 %d 不能被插入...\n", x);
		return 0;
	}
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不能按位置插入数据:%d\n", x);
		return;
	}
	for (int i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

//按值插入
void SeqListInsertByVal(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表已满，不能按值插入数据:%d\n", x);
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

//按位置删除
void SeqListIDeleteByPos(SeqList *pst, int pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能按位值删除数据...\n");
		return;
	}
	if (pos < 0 || pos >= pst->size)
	{
		printf("要删除的位置非法，不能按位值删除数据...\n");
		return 0;
	}
	for (int i = pos; i < pst->size; i++)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

//按值删除
void SeqListIDeleteByVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能按值删除数据...\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("要删除的值不存在...\n");
		return;
	}
	else
	{
		SeqListIDeleteByPos(pst, pos);
	}
}

//删除所有匹配的元素
void SeqListRemoveAll(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表已空，不能按值删除数据...\n");
		return;
	}
	int pos = SeqListFind(pst, key);
	if (pos == -1)
	{
		printf("要删除的值不存在...\n");
		return;
	}
	while (SeqListFind(pst, key) != -1)
	{
		SeqListIDeleteByPos(pst, pos);
	}
}

//排序
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

//查找
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

//转置顺序表
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

//清空线性表
void SeqListClear(SeqList *pst)
{
	assert(pst != NULL);
	pst->size = 0;
}

//显示SeqList的内容
void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空...\n");
		return 0;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

//摧毁pst->base
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