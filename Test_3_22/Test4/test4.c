#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu()
{
	printf("*********************\n");
	printf("**     猜 数 字    **\n");
	printf("** 1.play   0.exit **\n");
	printf("*********************\n");
}
void game()
{
	int guess = 0;
	int count = 4;
	int ret = rand() % 100 + 1;
	while ( count > 0)
	{
		printf("\n请输入数字：>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			if (count > 1)
				printf("猜大了,你还有%d次机会!\n", count);
			count--;
		}
		else if (guess < ret)
		{
			if (count > 1)
				printf("猜小了,你还有%d次机会!\n", count-1);
			count--;
		}
		else 
		{
			printf("恭喜你，猜对了!\n");
			Sleep(1000);
			break;
		}
	}
	
	if (count == 0)
	{
		printf("boom! boom! boom! you're dead!\n");
	}
	system("pause");
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));//只调用一次
	do
	{
		system("cls");
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("这里里有一个1-100之间的数字，请你来猜一猜，你只有4次机会。\n");
			game();
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