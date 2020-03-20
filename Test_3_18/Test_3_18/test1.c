#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10;
	int* p = &a;
	//printf("a = %d\n", a);
	//printf("%p\n", p);
	*p = 20;
	printf("a = %d\n", a);
	system("pause");
	return 0;
}