#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


void Swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main()
{
	int a = 10000000000;
	int b = 2000000000;
	//scanf("%d %d", &a, &b);
	printf("a = %d, b = %d\n", a, b);

	Swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}