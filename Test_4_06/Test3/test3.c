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
		printf("这是小端模式\n");
	}
	else
	{
		printf("这时大端模式\n");
	}
	system("pause");
	return 0;
}