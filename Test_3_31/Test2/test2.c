#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i = 0;
	int sum = (++i) + (++i) + (++i);
	printf("%d\n", sum);
	system("pause");
	return 0;
}