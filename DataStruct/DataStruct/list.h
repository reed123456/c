#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

///////////////////////////////////////////////////////////////////////////////////
//单链表的函数接口声明
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);
void SListPushFront(SList *plist, ElemType x);
void SListPopBack(SList *plist);
void SListPopFront(SList *plist);
void SListDestroy(SList *plist);

void SListInsertByVal(SList *plist, ElemType x);

SListNode* SListFind(SList *plist, ElemType key);
void SListDeleteByVal(SList *plist, ElemType key);

void SListClear(SList *plist);
size_t SListLength(SList *plist);

void SListReverse(SList *plist);
void SListSort(SList *plist);

void SListShow(SList *plist);

//////////////////////////////////////////////////////////////////////////////////
//单链表的函数接口实现

//申请节点
static SListNode* _Buynode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

//初始化head指针
void SListInit(SList *plist)
{
	plist->head = NULL;
}

//尾插
void SListPushBack(SList *plist, ElemType x)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x);

	//插入的节点为第一个节点
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}

	//O(n)
	SListNode *p = plist->head;
	//查找链表的尾部节点 
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}

//头插
void SListPushFront(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *s = _Buynode(x);

	//O(1)
	s->next = plist->head;
	plist->head = s;
}

//尾删
void SListPopBack(SList *plist)
{
	assert(plist != NULL);
	SListNode *p, *prev;
	if (plist->head == NULL)
		return;
	p = plist->head;
	//链表只有一个节点
	if (p->next == NULL)
		plist->head = NULL;
	else
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		prev->next = NULL;
	}
	free(p);
}

//头删除
void SListPopFront(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	if (plist->head == NULL)
		return;

	plist->head = p->next;
	free(p);
}

//按值查找
SListNode* SListFind(SList *plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *p = plist->head;

	//空链表 NULL
	//存在   P
	//不存在 NULL

	while (p != NULL && p->data != key)
		p = p->next;
	return p;
}

//按值删除
void SListDeleteByVal(SList *plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = SListFind(plist, key);
	if (p == NULL)
	{
		printf("要删除的节点不存在.\n");
		return;
	}

	if (p == plist->head)
		plist->head = p->next;
	else
	{
		prev = plist->head;
		while (prev->next != p)
			prev = prev->next;

		//删除节点
		prev->next = p->next;
	}
	free(p);
}

//链表长度
size_t SListLength(SList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode *p = plist->head;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//打印链表
void SListShow(SList *plist)
{
	assert(plist != NULL);
	SListNode * p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

//摧毁链表
void SListDestroy(SList *plist)
{
	SListClear(plist);
	plist->head = NULL;
}

//清空链表
void SListClear(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}

//链表逆序
void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q;
	if (p->next == NULL)
		return;

	//断开第一个节点
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

//按值插入
void SListInsertByVal(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = plist->head;

	SListNode *s = _Buynode(x);

	while (p != NULL && x>p->data)
	{
		prev = p;
		p = p->next;
	}

	if (prev == NULL) //需要进行头插
	{
		s->next = p;
		plist->head = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

//排序
void SListSort(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q, *t, *prev = NULL;

	plist->head->next = NULL; //断开链表

	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		//把p节点摘除进行按值插入，升序
		while (t != NULL && p->data > t->data)
		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
		t = plist->head;
	}
}

#endif /* _LIST_H_ */