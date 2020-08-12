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
	system("title 二叉树");
	printf("*********************************************\n");
	printf("*  [1]creat_tree           [2]VLR           *\n");
	printf("*  [3]LVR                  [4]LRV           *\n");
	printf("*  [5]tree_size            [6]tree_high     *\n");
	printf("*  [7]find_node            [8]find_parent   *\n");
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
			printf("请输入所要创建的树：>");
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
			printf("二叉树节点个数 Size = %d\n", BinTreeCount(&bt));
			break;
		case 6:
			printf("二叉树深度 Height = %d\n", BinTreeHeight(&bt));
			break;
		case 7:
			printf("请输入所要查找的值key:>");
			scanf("%*c%c", &key);
			p = BinTreeFind(&bt, key);
			if (p != NULL)
				printf("%c 的地址为 %p\n", key, p);
			else
				printf("节点不存在...\n");
			break;
		case 8:
			printf("请输入所要查找的值key:>");
			scanf("%*c%c", &key);
			p = BinTreeParent(&bt, key);
			if (p != NULL)
				printf("%c 的父节点为 %c\n", key, p->data);
			else
				printf("节点不存在或没有父节点...\n");
			break;
		default:
			printf("输入有误，请重新输入...");
		}
	}
	BinTreeDestroy(&bt);
	system("pause");
	return 0;
}
