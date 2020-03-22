#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu()
{
	printf("*********************\n");
	printf("** 1.play   0.exit **\n");
	printf("*********************\n");
}
void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	while (1)
	{
		printf("猜数字：");
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了.\n");
		}
		else if (guess < ret)
		{
			printf("猜小了.\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			Sleep(1000);
			break;
		}
	}
}
int main()
{
	int input;
	srand((unsigned int)time(NULL));//只调用一次
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("cls");
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}