#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int x, int y)
{
	int sum;
	sum = x + y;
	return sum;
}

int main()
{
	//int a = (int)3.14;
	int a = 3;//局部变量-auto
	int b = 5;
	int c = 0;
	int d = 0;
	int max = 0;
	if (a && b){
		printf("嘿\n");
	}
	if (c || d){
		printf("嘿\n");
	}
	if (a > b){
		printf("max = %d\n", max);
	}
	else{
		printf("max = %d\n", max);
	}
	max = (a > b) ? a : b;
	printf("max = %d\n", max);

	printf("sum = %d\n", Add(c, a));
	system("pause");
	return 0;
}