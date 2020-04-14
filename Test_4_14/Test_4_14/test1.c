#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct tree   //二叉树的结点类型； 
{
	char ch;
	struct tree *lchild;
	struct tree *rchild;
}BitTree;
BitTree *CreateTree()//创建树；
{
	BitTree *bt;
	char str;
	scanf("%c", &str);
	if (str == '#')
		return NULL;
	else
	{
		bt = (BitTree *)malloc(sizeof(BitTree));
		bt->ch = str;
		bt->lchild = CreateTree();
		bt->rchild = CreateTree();
		return bt;
	}
}//交换左右二叉树；
void Exchange(BitTree *bt)
{
	if (bt->lchild == NULL&&bt->rchild == NULL)
		; else    //三种情况，1.都不为空，2.左为空，3.右为空；
	{
		BitTree *temp = bt->lchild;//交换左右子树；
		bt->lchild = bt->rchild;
		bt->rchild = temp;
	}//如果交换后的这个结点左子树不为空，则继续向下寻找可以交换的结点；
	if (bt->lchild)    		Exchange(bt->lchild);
	if (bt->rchild)          Exchange(bt->rchild);
}//先序输出交换后的二叉树；
void PreOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		printf("%c ", bt->ch);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}//中序输出交换后的二叉树；
void InOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%c ", bt->ch);
		InOrder(bt->rchild);
	}
}//后序输出交换后的二叉树；
void PostOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%c ", bt->ch);
	}
} int main()
{
	BitTree *bt;//创建二叉树；
	printf("请以先序序列输入需要交换的二叉树:\n");
	bt = CreateTree();
	Exchange(bt);	//交换左右子树；
	printf("交换后以先序序列输出:\n");//先序输出；
	PreOrder(bt); printf("\n");
	printf("交换后以中序序列输出:\n");//中序输出；
	InOrder(bt); printf("\n");
	printf("交换后以后序序列输出:\n");//后序输出；
	PostOrder(bt); printf("\n");
	system("pause");
	return 0;
}