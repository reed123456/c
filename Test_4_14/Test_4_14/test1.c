#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct tree   //�������Ľ�����ͣ� 
{
	char ch;
	struct tree *lchild;
	struct tree *rchild;
}BitTree;
BitTree *CreateTree()//��������
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
}//�������Ҷ�������
void Exchange(BitTree *bt)
{
	if (bt->lchild == NULL&&bt->rchild == NULL)
		; else    //���������1.����Ϊ�գ�2.��Ϊ�գ�3.��Ϊ�գ�
	{
		BitTree *temp = bt->lchild;//��������������
		bt->lchild = bt->rchild;
		bt->rchild = temp;
	}//������������������������Ϊ�գ����������Ѱ�ҿ��Խ����Ľ�㣻
	if (bt->lchild)    		Exchange(bt->lchild);
	if (bt->rchild)          Exchange(bt->rchild);
}//�������������Ķ�������
void PreOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		printf("%c ", bt->ch);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}//�������������Ķ�������
void InOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		InOrder(bt->lchild);
		printf("%c ", bt->ch);
		InOrder(bt->rchild);
	}
}//�������������Ķ�������
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
	BitTree *bt;//������������
	printf("������������������Ҫ�����Ķ�����:\n");
	bt = CreateTree();
	Exchange(bt);	//��������������
	printf("�������������������:\n");//���������
	PreOrder(bt); printf("\n");
	printf("�������������������:\n");//���������
	InOrder(bt); printf("\n");
	printf("�������Ժ����������:\n");//���������
	PostOrder(bt); printf("\n");
	system("pause");
	return 0;
}