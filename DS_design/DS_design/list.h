/*list.h*/
#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include <vld.h>
#include <malloc.h>

#define ElemType int

//////////////////////////////////////////////////////////////////////////////////
//����ͷ�ĵ�����
typedef struct SListNode
{
	ElemType data[2];
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

///////////////////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�����
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);
void SListPushBack(SList *plist, ElemType x);
void SListDestroy(SList *plist);
void SListShow(SList *plist);
bool IsEmpty(SList *plist);

void Addlist(SList *palist, SList *pblist);
void SUBlist(SList *palist, SList *pblist);
//////////////////////////////////////////////////////////////////////////////////
//������ĺ����ӿ�ʵ��

//����ڵ�
static SListNode* _Buynode(ElemType x, ElemType index)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data[0] = x;
	s->data[1] = index;
	s->next = NULL;
	return s;
}

//��ʼ��headָ��
void SListInit(SList *plist)
{
	plist->head = NULL;
}

//β��
void SListPushBack(SList *plist, ElemType x, ElemType index)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x, index);

	//����Ľڵ�Ϊ��һ���ڵ�
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}

	//O(n)
	SListNode *p = plist->head;
	//���������β���ڵ� 
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}

bool IsEmpty(SList *plist)
{
	return plist->head == NULL;
}
void Addlist(SList *palist, SList *pblist)
{
	SListNode* pa;
	SListNode* pb;
	SListNode* plast;
	SListNode* ppre = NULL;
	SListNode* tmp;
	if (palist == NULL)
	{
		palist->head = pblist->head;
		pblist->head = NULL;
		return;
	}

	pa = palist->head;
	pb = pblist->head;

	plast = pa;
	if (pa->data[1] < pb->data[1])
	{
		pa = pb;
		pb = plast;
	}


	while (plast->next != NULL && pb != NULL)
	{
		if (pb->data[1] == plast->data[1])
		{
			plast->data[0] += pb->data[0];
			tmp = pb;
			pb = pb->next;
			free(tmp);
			if (plast->data[0] == 0)
			{
				if (plast == pa)
				{
					pa = pa->next;
					free(plast);
					plast = pa;
				}
				
				else
				{
					ppre->next = plast->next;
					plast = ppre;
				}

			}
		}
		else if (plast->data[1] > pb->data[1] && plast->next->data[1] < pb->data[1])
		{
			tmp = pb;
			pb = pb->next;
			tmp->next = plast->next;
			plast->next = tmp;
			ppre = plast;
			plast = tmp;
		}
		else if (plast->data[1] > pb->data[1] && plast->next->data[1] >= pb->data[1])
		{
			ppre = plast;
			plast = plast->next;
		}
	}
	if (pb != NULL && plast->data[1] == plast->data[1])
	{
		if (plast->data[1] == plast->data[1])
		{
			plast->data[0] += pb->data[0];
			if (plast->data[0] == 0)
			{
				ppre->next = pb->next;
				free(plast);
				pb = NULL;
			}
			free(pb);
		}
		else 
		{
			plast->next = pb;
		}
	}

	pblist->head = NULL;
	palist->head = pa;
}

//a+b
/*
void Addlist(SList *palist, SList *pblist)
{
	SListNode* pa;
	SListNode* pb;
	SListNode* plast;
	SListNode* ppre = NULL;
	SListNode* tmp;
	if (palist == NULL)
	{
		palist->head = pblist->head;
		pblist->head = NULL;
		return;
	}

	pa = palist->head;
	pb = pblist->head;

	plast = pa;
	if (pa->data[1] < pb->data[1])
	{
		pa = pb;
		pb = plast;
	}

	
	while (plast->next != NULL && pb != NULL)
	{
		if (pb->data[1] == plast->data[1])
		{
			plast->data[0] += pb->data[0];
			tmp = pb;
			pb = pb->next;
			free(tmp);
			if (plast->data[0] == 0)
			{
				if (plast == pa)
				{
					pa = pa->next;
					free(plast);
					plast = pa;
				}
				else
				{
					ppre->next = plast->next;
					plast = ppre;
				}
				
			}
		}
		else if (plast->data[1] > pb->data[1] && plast->next->data[1] < pb->data[1])
		{
			tmp = pb;
			pb = pb->next;
			tmp->next = plast->next;
			plast->next = tmp;
			ppre = plast;
			plast = tmp;
		}
		else if(plast->data[1] > pb->data[1] && plast->next->data[1] >= pb->data[1])
		{
			ppre = plast;
			plast = plast->next;
		}
	}
	if (pb != NULL)
	{
		plast->data[0] += pb->data[0];
		free(pb);
		pb = NULL;
	}
	pblist->head = pa;
	palist->head = pa;
}
*/
//a-b
void Sublist(SList *palist, SList *pblist)
{
	SListNode* pb = pblist->head;
	while (pb != NULL)
	{
		pb->data[0] *= -1;
		pb = pb->next;
	}
	Addlist(palist, pblist);
}


//��ӡ����
void SListShow(SList *plist)
{
	assert(plist != NULL);
	SListNode * p = plist->head;
	printf("%dx^%d", p->data[0], p->data[1]);
	p = p->next;
	while (p != NULL)
	{
		if (p->data[0] > 0)
			printf("+");
		if (p->next == NULL)
		{
			if (p->data[1] == 1 || p->data[1] == 0)
				printf("%d", p->data[0]);
			else
				printf("%dx^%d",  p->data[0], p->data[1]);
		}
		else
			printf("%dx^%d", p->data[0], p->data[1]);
		p = p->next;
	}
	printf("\n");
}

//�ݻ�����
void SListDestroy(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
	plist->head = NULL;
}

#endif /* _LIST_H_ */