#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int a = 0;
	int b = 0;
	max(a, b);
	system("pause");
	return 0;
}