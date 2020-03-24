#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int get_max(int x, int y)
{
	return (x > y ? x : y);
}

void Swap(int * x, int * y)
{
	int *temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	printf("a = %d, b = %d\n", a, b);
	max = get_max(a, b);
	printf("max = %d\n", max);
	Swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}