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
				printf("Ҫ���ҵ�ֵ��λ��Ϊ��%d\n", pos);
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