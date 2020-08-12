//
//#include "list.h"
//
//int main()
//{
//	SList a, b;
//
//	SListInit(&a);
//	SListInit(&b);
//	ElemType item, index;
//	printf("请输入要插入的值[以-1结束]:>");
//	while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
//	{
//	SListPushBack(&a, item, index);
//	}
//	printf("尾部插入数据成功...\n");
//
//	printf("a = ");
//	SListShow(&a);
//
//	printf("请输入要插入的值[以-1结束]:>");
//	while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
//	{
//	SListPushBack(&b, item, index);
//	}
//	printf("尾部插入数据成功...\n");
//	printf("b = ");
//	SListShow(&b);
//	Addlist(&a, &b);
//	printf("a+b = ");
//	SListShow(&a);
//	SListDestroy(&a);
//
//
//	printf("GoodBye......\n");
//
//	system("pause");
//	return 0;
//}

/*cal.c*/
#include "list.h"

int main()
{
	SList a, b;
	int select = 1;
	SListInit(&a);
	SListInit(&b);

	ElemType item, index;
	system("title 一元稀疏多项式简单计数器");
	printf("*********************************************\n");
	printf("*  [1]creat_a              [2]creat_b       *\n");
	printf("*  [3]a+b                  [4]a-b           *\n");
	printf("*  [0]exit                                  *\n");
	printf("*********************************************\n");
	while (select)
	{
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入多项式的底数item及指数index\n[以item == 0 && index == 0结束]\n>");
			while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
				SListPushBack(&a, item, index);

			printf("a = ");
			SListShow(&a);
			break;
		case 2:
			printf("请输入要插入多项式的底数item及指数index\n[以item == 0 && index == 0结束]\n>");
			while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
				SListPushBack(&b, item, index);

			printf("b = ");
			SListShow(&b);
			break;
		case 3:
			if (!IsEmpty(&a) && !IsEmpty(&b))
			{
				Addlist(&a, &b);
				printf("a + b = ");
				if (!IsEmpty(&a))
				{
					SListShow(&a);
					SListDestroy(&a);
				}
				else
				{
					SListShow(&b);
					SListDestroy(&b);
				}
			}
			else
				printf("你应该先创建多项式a和b...\n");
			break;
		case 4:
			if (!IsEmpty(&a) && !IsEmpty(&b))
			{
				Sublist(&a, &b);
				printf("a - b = ");
				if (!IsEmpty(&a))
				{
					SListShow(&a);
					SListDestroy(&a);
				}
				else
				{
					SListShow(&b);
					SListDestroy(&b);
				}
			}
			else
			{
				printf("你应该先创建多项式a和b...\n");
			}
			break;
		default :
			printf("输入有误，请重新输入>");
			continue;

		}
	}

	printf("GoodBye......\n");

	system("pause");
	return 0;
}