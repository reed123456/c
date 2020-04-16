#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct A
{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
}A;

int main()
{
	printf("%d\n", sizeof(A));
	system("pause");
	return 0;
}