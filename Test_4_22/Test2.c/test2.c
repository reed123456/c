#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ADD(A, B) printf(#A " + " #B " = %d\n", A + B)
int main()
{
	int a = 10;
	int b = 20;
	ADD(10, 20);
	//int ret = ADD(a, b);
	//printf("ret = %d\n", ret);
	//printf("%d\n", __LINE__);
	system("pause");
	return 0;
}