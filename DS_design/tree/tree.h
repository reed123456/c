/*tree.h*/
#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include <vld.h>
#include <malloc.h>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;


//初始化
void BinTreeInit(BinTree *pbt);
//创建
void BinTreeCreateByStr(BinTree *bt, const char *str);
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex);

//递归遍历
void PreOrder(BinTree *bt);
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *bt);
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *bt);
void PostOrder_1(BinTreeNode *t);

//求二叉树的节点个数以及树的高度
int BinTreeCount(BinTree *bt);
int BinTreeCount_1(BinTreeNode *t);
int BinTreeHeight(BinTree *bt);
int BinTreeHeight_1(BinTreeNode *t);

//查询
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key);
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key);
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key);
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key);


//摧毁二叉树
void BinTreeDestroy(BinTree *bt);
void BinTreeDestroy_1(BinTreeNode *t);
//==================================================

//初始化
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}

//创建二叉树(通过字符串)
void BinTreeCreateByStr(BinTree *bt, const char *str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str, &index);
}
//"ABC##DE##F##G#H##";
BinTreeNode* BinTreeCreateByStr_1(const char *str, int *pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}

//遍历
//VLR
void PreOrder(BinTree *bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}

//LVR
void InOrder(BinTree *bt)
{
	InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c ", t->data);
		InOrder_1(t->rightChild);
	}
}

//LRV
void PostOrder(BinTree *bt)
{
	PostOrder_1(bt->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c ", t->data);
	}
}

//二叉树节点个数
int BinTreeCount(BinTree *bt)
{
	return BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
		return BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild) + 1;
}

//二叉树深度
int BinTreeHeight(BinTree *bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = BinTreeHeight_1(t->leftChild);
		int right_h = BinTreeHeight_1(t->rightChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}

//查询
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL || t->data == key)
		return t;
	p = BinTreeFind_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return BinTreeFind_1(t->rightChild, key);
}

//父节点
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key)
{
	return BinTreeParent_1(bt->root, key);
}
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL || t->data == key)
		return NULL;
	if ((t->leftChild != NULL && t->leftChild->data == key)
		|| (t->rightChild != NULL && t->rightChild->data == key))
		return t;
	p = BinTreeParent_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return BinTreeParent_1(t->rightChild, key);
}

//摧毁二叉树
void BinTreeDestroy(BinTree *bt)
{
	BinTreeDestroy_1(bt->root);
}
void BinTreeDestroy_1(BinTreeNode *t)
{
	if (t == NULL)
		return;
	BinTreeDestroy_1(t->leftChild);
	BinTreeDestroy_1(t->rightChild);
	free(t);
}


#endif /* _TREE_H_ */