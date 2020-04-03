#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//数组
	int arr[10] = { 0 };
	char ch[5] = { 0 };

	//指针数组
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int * arr2[5] = { &a, &b, &c, &d };
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", *(arr2[i]));
	}
	printf("\n");

	system("pause");
	return 0;
}