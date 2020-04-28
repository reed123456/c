#include<vld.h>
#include"Contact.h"

void Menu()
{
	printf("*********************ͨѶ¼*******************\n");
	printf("*        [1] Add            [2] Del          *\n");
	printf("*        [3] Find           [4] Modify       *\n");
	printf("*        [5] Show           [6] Clear        *\n");
	printf("*        [7] Sort           [0] Quit         *\n");
	printf("**********************************************\n");
}

int main(int argc, char *argv[])
{
	system("title ͨѶ¼����ϵͳ");
	system("mode con cols=46 lines=23");
	system("color 0F");

	Contact cont; //����ͨѶ¼����
	InitContact(&cont);

	int select = 1;
	while (select)
	{
		Menu();
		printf("��ѡ��:>");
		scanf("%d", &select);
		if (select == QUIT)
			break;
		system("cls");
		Menu();
		switch (select)
		{
		case ADD:
			AddContact(&cont);
			break;
		case DEL:
			DelContact(&cont);
			break;
		case FIND:
			FindContact(&cont);
			break;
		case MODIFY:
			ModifyContact(&cont);
			break;
		case SHOW:
			ShowContact(&cont);
			break;
		case CLEAR:
			ClearContact(&cont);
			break;
		case SORT:
			SortContact(&cont);
			break;
		default:
			printf("����ѡ���������������...\n");
			break;
		}
		system("pause");
		system("cls");
	}

	SaveContact(&cont);

	DestroyContact(&cont);
	printf("�˳�ͨѶ¼ϵͳ��Good Bye......\n");
	system("pause");
	return 0;
}