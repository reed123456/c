#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//大端（存储）模式，是指数据的低位保存在内存的高地址中，而数据的高位，保存在内存的低地址中；
//小端（存储）模式，是指数据的低位保存在内存的低地址中，而数据的高位, ，保存在内存的高地址中
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
		printf("小端存储模式\n");
	}
	else
	{
		printf("大端存储模式\n");
	}
	system("pause");
	return 0;
}