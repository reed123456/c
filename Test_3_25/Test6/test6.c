#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//µÝ¹é
int Fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}

//·ÇµÝ¹é
int Fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", Fib1(n));
	printf("%d\n", Fib2(n));
	system("pause");
	return 0;
}