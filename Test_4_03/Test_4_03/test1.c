#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//二级指针
	int a = 10;
	int *pa = &a;//一级指针
	int **ppa = &pa;//二级指针
	printf("%d\n", **ppa);
	system("pause");
	return 0;
}