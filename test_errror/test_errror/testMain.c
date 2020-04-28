#include "seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInIt(&mylist);

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
				printf("要查找的值的位置为：%d\n", pos);
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