#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu()
{
	printf("*********************\n");
	printf("**     �� �� ��    **\n");
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
		printf("\n���������֣�>");
		scanf("%d", &guess);
		if (guess > ret)
		{
			if (count > 1)
				printf("�´���,�㻹��%d�λ���!\n", count);
			count--;
		}
		else if (guess < ret)
		{
			if (count > 1)
				printf("��С��,�㻹��%d�λ���!\n", count-1);
			count--;
		}
		else 
		{
			printf("��ϲ�㣬�¶���!\n");
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
	srand((unsigned int)time(NULL));//ֻ����һ��
	do
	{
		system("cls");
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("��������һ��1-100֮������֣���������һ�£���ֻ��4�λ��ᡣ\n");
			game();
			break;
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}