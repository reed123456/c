#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char input[100] = { 0 };
	system("shutdown -s -t 600");
again:
	printf("你的电脑将在10分钟之内关机，如果输入 我是猪 就取消关机\n");
	printf("请输入：>");
	scanf("%s", input);
	if (0 == strcmp(input, "我是猪"))
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	system("pause");
	return 0;
}