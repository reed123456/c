#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
int main()
{
	int a = 3;
	int b = 5; 
	//int c = a & b;//按位与
	//int c = a | b;//按位或
	int c = a ^ b;//按位异或
	printf("c = %d\n", c);
	system("pause");
	return 0;
}
*/
int main()
{
	int a = 3;
	int b = 5;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	//把a,b交换，不使用临时变量
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	system("pause");
	return 0;
}