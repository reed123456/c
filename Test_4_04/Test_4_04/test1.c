#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct S
{
	int a;
	int b;
};

int main()
{
	struct S a, *p = &a;
	a.a = 99;
	printf("%d\n", (*p).a);
	system("pause");
	return 0;
}