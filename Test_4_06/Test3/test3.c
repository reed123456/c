#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

bool CheckModel()
{
	int i = 1;
	return (*(char *)&i) == 1;
}

int main()
{
	int flag = CheckModel();
	if (flag)
	{
		printf("����С��ģʽ\n");
	}
	else
	{
		printf("��ʱ���ģʽ\n");
	}
	system("pause");
	return 0;
}