#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Sum(int a)
{
	int temp = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		temp = temp * 10 + a;
		sum += temp;
	}
	return sum;
}


int main()
{
	int a = 0;
	scanf("%d", &a);

	printf("%d\n", Sum(a));
	system("pause");
	return 0;
}