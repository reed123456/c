#include"seqlist.h"
#include"list.h"
#include"stack.h"
#include"queue.h"

void main()
{
	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEnQue(&Q, 1);
	LinkQueueEnQue(&Q, 2);
	LinkQueueEnQue(&Q, 3);
	LinkQueueEnQue(&Q, 4);

	LinkQueueDeQue(&Q);
	LinkQueuePrint(&Q);

}

/*
void main()
{
CircleQueue Q;
CircleQueueInit(&Q);
CircleQueueEnque(&Q, 1);
CircleQueueEnque(&Q, 2);
CircleQueueEnque(&Q, 3);
CircleQueueEnque(&Q, 4);
CircleQueueEnque(&Q, 5);
CircleQueueEnque(&Q, 6);
CircleQueueEnque(&Q, 7);
CircleQueueEnque(&Q, 8);
CircleQueueDeque(&Q);
CircleQueueEnque(&Q, 9);
CircleQueuePrint(&Q);
printf("��ͷ = %d\n", CircleQueueFront(&Q));
}
//------------------------------------------------------------------------------------------------
/*
void main()
{
SeqQueue Q;
SeqQueueInit(&Q);
SeqQueueEnque(&Q, 1);
SeqQueueEnque(&Q, 2);
SeqQueueEnque(&Q, 3);
SeqQueueEnque(&Q, 4);
SeqQueueEnque(&Q, 5);
SeqQueueEnque(&Q, 6);
SeqQueueEnque(&Q, 7);
SeqQueueEnque(&Q, 8);
SeqQueueDeque(&Q);
SeqQueueEnque(&Q, 9);
SeqQueuePrint(&Q);
}
//------------------------------------------------------------------------------------------------
/*
void main()
{
	SeqQueue Q;
	SeqQueueInit(&Q);
	SeqQueueEnque(&Q, 1);
	SeqQueueEnque(&Q, 2);
	SeqQueueEnque(&Q, 3);
	SeqQueueEnque(&Q, 4);
	SeqQueueEnque(&Q, 5);
	SeqQueueEnque(&Q, 6);
	SeqQueueEnque(&Q, 7);
	SeqQueueEnque(&Q, 8);
	SeqQueueEnque(&Q, 9);
	SeqQueuePrint(&Q);
	printf("��ͷ = %d\n", SeqQueueFront(&Q));
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	printf("��ͷ = %d\n", SeqQueueFront(&Q));
}
//------------------------------------------------------------------------------------------------
/*˳��ջ*/
/*
#include "stack.h"
void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	SeqStackPush(&st, 9);
	SeqStackPrint(&st);
	ElemType val = SeqStackTop(&st);
	SeqStackPop(&st); //6
	printf("%d ��ջ.\n", val);
	val = SeqStackTop(&st);
	SeqStackPop(&st); //5
	printf("%d ��ջ.\n", val);
	SeqStackPrint(&st);
	SeqStackDestroy(&st);
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------
/*˫����*/
/*
#include"list.h"

int main()
{
	DCList mylist;
	DCListInit(&mylist);

	DCListNode *p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("*********************************************\n");
		printf("*  [1]push_back             [2]push_front   *\n");
		printf("*  [3]show_list             [4]pop_back     *\n");
		printf("*  [5]pop_front             [6]insert_value *\n");
		printf("*  [7]delete_value          [8]find_value   *\n");
		printf("*  [9]length                [10]sort        *\n");
		printf("*  [11]reverse              [12]clear       *\n");
		printf("*  [0]quit_system                           *\n");
		printf("*********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			printf("β���������ݳɹ�...\n");
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			printf("ͷ���������ݳɹ�...\n");
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			printf("β��ɾ�����ݳɹ�...\n");
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			DCListSort(&mylist);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 7:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			printf("ɾ���ɹ�...\n");
			break;
		case 8:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ������.\n");
			else
				printf("Ҫ���ҵ�ֵΪ:> %p\n", &(p->data));
			break;
		case 9:
			printf("seqlist len = %d\n", DCListLength(&mylist));
			break;
		case 10:
			DCListSort(&mylist);
			printf("˳�������ɹ�......\n");
			break;
		case 11:
			DCListReverse(&mylist);
			break;
		case 12:
			DCListClear(&mylist);
			printf("������ݱ�ɹ�......\n");
			break;
		}
	}
	DCListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------
/*������(��ͷ���)*/
/*
#include"list.h"

int main()
{
	SList mylist;
	SListInit(&mylist);

	SListNode *p;
	ElemType item, key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("*********************************************\n");
		printf("*  [1]push_back             [2]push_front   *\n");
		printf("*  [3]show_list             [4]pop_back     *\n");
		printf("*  [5]pop_front             [6]insert_value *\n");
		printf("*  [7]delete_value          [8]find_value   *\n");
		printf("*  [9]length                [10]sort        *\n");
		printf("*  [11]reverse              [12]clear       *\n");
		printf("*  [0]quit_system                           *\n");
		printf("*********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			printf("β���������ݳɹ�...\n");
			break;
		case 2:
			printf("������Ҫ�����ֵ[��-1����]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			printf("ͷ���������ݳɹ�...\n");
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			printf("β��ɾ�����ݳɹ�...\n");
			break;
		case 5:
			SListPopFront(&mylist);
			printf("ͷ��ɾ�����ݳɹ�...\n");
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, pos, item);
			break;
		case 7:
			printf("������Ҫɾ����ֵ:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			printf("ɾ�����ݳɹ�...\n");
			break;
		case 8:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("Ҫ���ҵ�ֵ������.\n");
			else
				printf("Ҫ���ҵ�ֵΪ:> %p\n", &(p->data));
			break;
		case 9:
			printf("seqlist len = %d\n", SListLength(&mylist));
			break;
		case 10:
			SListSort(&mylist);
			printf("��������ɹ�......\n");
			break;
		case 11:
			SListReverse(&mylist);
			printf("��������ɹ�...\n");
			break;
		case 12:
			SListClear(&mylist);
			printf("������ݱ�ɹ�......\n");
			break;
		}
	}
	SListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
/*˳���*/
/* 
#include "seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInIt(&mylist);

	//printf("SeqList capacity = %d\n", SeqListCapacity(&mylist));
	//_Inc(&mylist);
	//printf("SeqList capacity = %d\n", SeqListCapacity(&mylist));

	ElemType item, key;
	int select = 1;
	int pos = 0;
	while (select)
	{
		printf("*********************************************\n");
		printf("*  [1]push_back             [2]push_front   *\n");
		printf("*  [3]show_list             [4]pop_back     *\n");
		printf("*  [5]pop_front             [6]insert_pos   *\n");
		printf("*  [7]insert_value          [8]delete_pos   *\n");
		printf("*  [9]delete_value          [10]find_value  *\n");
		printf("*  [11]length               [12]capacity    *\n");
		printf("*  [13]sort                 [14]reverse     *\n");
		printf("*  [15]clear                [16]remove_all  *\n");
		printf("*  [0]quit_system                           *\n");
		printf("*********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�����ֵ��1�� -1 ������:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			printf("β���������ݳɹ�...\n");
			break;
		case 2:
			printf("������Ҫ�����ֵ��1�� -1 ������:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			printf("ͷ���������ݳɹ�...\n");
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			printf("ɾ���ɹ�...\n");
			break;
		case 5:
			SeqListPopFront(&mylist);
			printf("ɾ���ɹ�...\n");
			break;
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			printf("�������ݳɹ�...\n");
			break;
		case 7:
			SeqListSort(&mylist);
			printf("������Ҫ���������:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			printf("�������ݳɹ�...\n");
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			SeqListIDeleteByPos(&mylist, pos);
			printf("ɾ���ɹ�...\n");
			break;
		case 9:
			printf("������Ҫɾ��������:>");
			scanf("%d", &key);
			SeqListIDeleteByVal(&mylist, key);
			printf("ɾ���ɹ�...\n");
			break;
		case 10:
			printf("������Ҫ���ҵ�ֵ:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
			{
				printf("Ҫ���ҵ�ֵ������...\n");
			}
			else
			{
				printf("Ҫ���ҵ�ֵ��λ��Ϊ��%d\n",pos);
			}
			break;
		case 11:
			printf("SeqList length = %d\n", SeqListLength(&mylist));
			break;
		case 12:
			printf("SeqList capacity = %d\n", SeqListCapacity(&mylist));
			break;
		case 13:
			SeqListSort(&mylist);
			printf("˳�������ɹ�...\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			printf("˳�������ɹ�...\n");
			break;
		case 15:
			SeqListClear(&mylist);
			printf("������ݱ�ɹ�...\n");
			break;
		case 16:
			printf("������Ҫɾ��������:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			printf("ɾ���ɹ�...\n");
			break;
		}
	}
	SeqListDestroy(&mylist);
	printf("Cood by...\n");
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------