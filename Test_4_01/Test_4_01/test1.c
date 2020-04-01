#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 2147483647;
	int b = 2147483646;
	printf("a = %d", a);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}