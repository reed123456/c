#include "tree.h"


//ABC##DE##F##g#H##

void main()
{
	const char *VLR = "ABCDEFGH";  //VLR+LVR ==> 
	const char *LVR = "CBEDFAGH";
	const char *LRV = "CEFDBHGA";  //LRV+LVR ==>     //VLR + LRV ==> ?

	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreateByStr(&bt, str);

	printf("VLR: ");
	PreOrder_NoR(&bt);
	printf("\n");

	BinTreeDestroy(&bt);
	system("pause");
	return 0;
}

//------------------------------------------------------------------------------------------------
//ABC##DE##F##g#H##
/*二叉树*/
/*
#include"tree.h"
void main()
{
	//const char *str = "AB#DF###CE###";
	const char *str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);
	printf("VLR: ");
	PreOrder(&bt);
	printf("\n");

	printf("LVR: ");
	InOrder(&bt);
	printf("\n");

	printf("LRV: ");
	PostOrder(&bt);
	printf("\n");

	printf("Level: ");
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", BinTreeCount(&bt));
	printf("Height = %d\n", BinTreeHeight(&bt));
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------
/*链队列*/
/*
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
*/
//------------------------------------------------------------------------------------------------
/*循环队列*/
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
	CircleQueueDeque(&Q);
	CircleQueueEnque(&Q, 9);
	CircleQueueEnque(&Q, 10);
	CircleQueueEnque(&Q, 11);
	CircleQueueEnque(&Q, 12);
	CircleQueuePrint(&Q);
	printf("对头 = %d\n", CircleQueueFront(&Q));
	system("pause");
}
*/
//------------------------------------------------------------------------------------------------
/*顺序队列*/
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
	system("pause");
	return 0;
}
*/
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
	printf("对头 = %d\n", SeqQueueFront(&Q));
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	SeqQueueDeque(&Q);
	SeqQueuePrint(&Q);
	printf("对头 = %d\n", SeqQueueFront(&Q));
}
//------------------------------------------------------------------------------------------------
/*顺序栈*/
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
	printf("%d 出栈.\n", val);
	val = SeqStackTop(&st);
	SeqStackPop(&st); //5
	printf("%d 出栈.\n", val);
	SeqStackPrint(&st);
	SeqStackDestroy(&st);
	system("pause");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------
/*双链表*/
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
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushBack(&mylist, item);
			}
			printf("尾部插入数据成功...\n");
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				DCListPushFront(&mylist, item);
			}
			printf("头部插入数据成功...\n");
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			printf("尾部删除数据成功...\n");
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			DCListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			DCListInsertByVal(&mylist, item);
			break;
		case 7:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			DCListDeleteByVal(&mylist, key);
			printf("删除成功...\n");
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = DCListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %p\n", &(p->data));
			break;
		case 9:
			printf("seqlist len = %d\n", DCListLength(&mylist));
			break;
		case 10:
			DCListSort(&mylist);
			printf("顺序表排序成功......\n");
			break;
		case 11:
			DCListReverse(&mylist);
			break;
		case 12:
			DCListClear(&mylist);
			printf("清除数据表成功......\n");
			break;
		}
	}
	DCListDestroy(&mylist);
	printf("GoodBye......\n");
	return 0;
}
*/
//------------------------------------------------------------------------------------------------
/*单链表(无头结点)*/
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
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushBack(&mylist, item);
			}
			printf("尾部插入数据成功...\n");
			break;
		case 2:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SListPushFront(&mylist, item);
			}
			printf("头部插入数据成功...\n");
			break;
		case 3:
			SListShow(&mylist);
			break;
		case 4:
			SListPopBack(&mylist);
			printf("尾部删除数据成功...\n");
			break;
		case 5:
			SListPopFront(&mylist);
			printf("头部删除数据成功...\n");
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SListInsertByVal(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SListDeleteByVal(&mylist, key);
			printf("删除数据成功...\n");
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			p = SListFind(&mylist, key);
			if (p == NULL)
				printf("要查找的值不存在.\n");
			else
				printf("要查找的值为:> %p\n", &(p->data));
			break;
		case 9:
			printf("seqlist len = %d\n", SListLength(&mylist));
			break;
		case 10:
			SListSort(&mylist);
			printf("链表排序成功......\n");
			break;
		case 11:
			SListReverse(&mylist);
			printf("链表逆序成功...\n");
			break;
		case 12:
			SListClear(&mylist);
			printf("清除数据表成功......\n");
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
/*顺序表*/
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
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值（1以 -1 结束）:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist, item);
			}
			printf("尾部插入数据成功...\n");
			break;
		case 2:
			printf("请输入要插入的值（1以 -1 结束）:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushFront(&mylist, item);
			}
			printf("头部插入数据成功...\n");
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			printf("删除成功...\n");
			break;
		case 5:
			SeqListPopFront(&mylist);
			printf("删除成功...\n");
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			printf("插入数据成功...\n");
			break;
		case 7:
			SeqListSort(&mylist);
			printf("请输入要插入的数据:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			printf("插入数据成功...\n");
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListIDeleteByPos(&mylist, pos);
			printf("删除成功...\n");
			break;
		case 9:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			SeqListIDeleteByVal(&mylist, key);
			printf("删除成功...\n");
			break;
		case 10:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFind(&mylist, key);
			if (pos == -1)
			{
				printf("要查找的值不存在...\n");
			}
			else
			{
				printf("要查找的值的位置为：%d\n",pos);
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
			printf("顺序表排序成功...\n");
			break;
		case 14:
			SeqListReverse(&mylist);
			printf("顺序表逆序成功...\n");
			break;
		case 15:
			SeqListClear(&mylist);
			printf("清除数据表成功...\n");
			break;
		case 16:
			printf("请输入要删除的数据:>");
			scanf("%d", &key);
			SeqListRemoveAll(&mylist, key);
			printf("删除成功...\n");
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