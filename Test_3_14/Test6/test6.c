#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 10;
	char c = 'a';
	int * pa = &a;
	char * pc = c;
	printf("%p\n", pa);
	printf("%p\n", &a);
	printf("a = %d\n", *pa);
	printf("pc:%d", sizeof(pa));//4 win32    8  win64
	printf("pa:%d", sizeof(pc));//4
	system("pause");
	return 0;
}