#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	//����ָ��
	int a = 10;
	int *pa = &a;//һ��ָ��
	int **ppa = &pa;//����ָ��
	printf("%d\n", **ppa);
	system("pause");
	return 0;
}