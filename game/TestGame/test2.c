#define _CRT_SECURE_NO_WARNINGS 1
#include "testgame.h"

void menu()
{
	printf("**********************\n");
	printf("**     扫   雷      **\n");
	printf("**     1.play       **\n");
	printf("**     0.exit       **\n");
	printf("**********************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//记录雷的数组
	char show[ROWS][COLS] = { 0 };//展示给玩家的数组
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//随机放雷
	SetMine(mine, ROW, COL);
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	menu();
	do
	{
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			menu();
			game();
			printf("是否继续游戏？(0 or 1)\n");
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("选择错误");
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