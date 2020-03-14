#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define MAX  100

enum Sex
{
	MALE,
	FAMALE,
	SECRET
};

int main()
{
	enum Sex s = MALE;
	//const int n = 10;//n是变量，具有长属性，不可以被改变
	int arr[10] = { 0 };
	int a = MAX;
	print("%d\n", a);

	
	printf("%d", MALE);
	printf("%d", FAMALE);
	printf("%d", SECRET);
	system("pause");
	return 0;
}