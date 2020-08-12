/*tree.c*/
#include"tree.h"
void main()
{
	//const char *str = "AB#DF###CE###";
	//ABC##DE##F##G#H##ABC##DE##F##G#H##
	int select = 1;
	BinTree  bt;
	ElemType key;
	BinTreeNode *p;
	char str[50];
	BinTreeInit(&bt);
	system("title ������");
	printf("*********************************************\n");
	printf("*  [1]creat_tree           [2]VLR           *\n");
	printf("*  [3]LVR                  [4]LRV           *\n");
	printf("*  [5]tree_size            [6]tree_high     *\n");
	printf("*  [7]find_node            [8]find_parent   *\n");
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
			printf("��������Ҫ����������>");
			scanf("%s", str);
			BinTreeCreateByStr(&bt, str);
			break;
		case 2:
			printf("VLR: ");
			PreOrder(&bt);
			printf("\n");
			break;
		case 3:
			printf("LVR: ");
			InOrder(&bt);
			printf("\n");
			break;
		case 4:
			printf("LRV: ");
			PostOrder(&bt);
			printf("\n");
			break;
		case 5:
			printf("�������ڵ���� Size = %d\n", BinTreeCount(&bt));
			break;
		case 6:
			printf("��������� Height = %d\n", BinTreeHeight(&bt));
			break;
		case 7:
			printf("��������Ҫ���ҵ�ֵkey:>");
			scanf("%*c%c", &key);
			p = BinTreeFind(&bt, key);
			if (p != NULL)
				printf("%c �ĵ�ַΪ %p\n", key, p);
			else
				printf("�ڵ㲻����...\n");
			break;
		case 8:
			printf("��������Ҫ���ҵ�ֵkey:>");
			scanf("%*c%c", &key);
			p = BinTreeParent(&bt, key);
			if (p != NULL)
				printf("%c �ĸ��ڵ�Ϊ %c\n", key, p->data);
			else
				printf("�ڵ㲻���ڻ�û�и��ڵ�...\n");
			break;
		default:
			printf("������������������...");
		}
	}
	BinTreeDestroy(&bt);
	system("pause");
	return 0;
}
