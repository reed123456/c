#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10;
	int *pa = &a;
	char *qa = &a;

	printf("%p\n", pa);
	printf("%p\n", pa + 1);
	printf("%p\n", qa);
	printf("%p\n", qa + 1);
	system("pause");
	return 0;
}