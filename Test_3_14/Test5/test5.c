#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MAX 100
#define ADD(x, y) ((x)+(y));
int Max(int x, int y)
{
	return(x > y ? x : y);
}

int main()
{
	int a = MAX;
	int b = 20;
	int max;
	int sum;
	printf("a = %d\n", a);
	max = Max(a, b);
	printf("max = %d\n", max);
	sum = ADD(a, b);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}