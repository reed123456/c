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
//	printf("������Ҫ�����ֵ[��-1����]:>");
//	while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
//	{
//	SListPushBack(&a, item, index);
//	}
//	printf("β���������ݳɹ�...\n");
//
//	printf("a = ");
//	SListShow(&a);
//
//	printf("������Ҫ�����ֵ[��-1����]:>");
//	while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
//	{
//	SListPushBack(&b, item, index);
//	}
//	printf("β���������ݳɹ�...\n");
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
	system("title һԪϡ�����ʽ�򵥼�����");
	printf("*********************************************\n");
	printf("*  [1]creat_a              [2]creat_b       *\n");
	printf("*  [3]a+b                  [4]a-b           *\n");
	printf("*  [0]exit                                  *\n");
	printf("*********************************************\n");
	while (select)
	{
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ�������ʽ�ĵ���item��ָ��index\n[��item == 0 && index == 0����]\n>");
			while (scanf("%d %d", &item, &index), !(item == 0 && index == 0))
				SListPushBack(&a, item, index);

			printf("a = ");
			SListShow(&a);
			break;
		case 2:
			printf("������Ҫ�������ʽ�ĵ���item��ָ��index\n[��item == 0 && index == 0����]\n>");
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
				printf("��Ӧ���ȴ�������ʽa��b...\n");
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
				printf("��Ӧ���ȴ�������ʽa��b...\n");
			}
			break;
		default :
			printf("������������������>");
			continue;

		}
	}

	printf("GoodBye......\n");

	system("pause");
	return 0;
}