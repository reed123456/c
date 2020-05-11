#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

//1、https://leetcode-cn.com/problems/valid-parentheses/  [有效的括号]
//链栈
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
	if (pst->top == NULL)
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
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
///////////////////////////////////////////////////////////////////////////////
//char *s = "{[()[()]()]}"

bool isValid(char * s)
{
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;

	LinkStack st;
	LinkStackInit(&st);

	while (*s != '\0')
	{
		if (*s == '{' || *s == '[' || *s == '(')
			LinkStackPush(&st, *s);
		else
		{
			if (LinkStackEmpty(&st))
				return false;

			char top = LinkStackTop(&st);
			if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
				return false;

			LinkStackPop(&st);
		}
		s++;
	}

	bool flag = LinkStackEmpty(&st);
	LinkStackDestroy(&st);
	return flag;
}