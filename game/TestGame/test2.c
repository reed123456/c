#define _CRT_SECURE_NO_WARNINGS 1
#include "testgame.h"

void menu()
{
	printf("**********************\n");
	printf("**     ɨ   ��      **\n");
	printf("**     1.play       **\n");
	printf("**     0.exit       **\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//��¼�׵�����
	char show[ROWS][COLS] = { 0 };//չʾ����ҵ�����
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//�������
	SetMine(mine, ROW, COL);
	//��ӡ����
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			menu();
			game();
			printf("�Ƿ������Ϸ��(0 or 1)\n");
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("ѡ�����");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}