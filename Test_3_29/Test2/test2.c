#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
int main()
{
	int a = 3;
	int b = 5; 
	//int c = a & b;//��λ��
	//int c = a | b;//��λ��
	int c = a ^ b;//��λ���
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
	//��a,b��������ʹ����ʱ����
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	system("pause");
	return 0;
}