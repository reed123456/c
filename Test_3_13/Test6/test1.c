#include <stdio.h>

int Add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

int main()
{
	int num1;
	int num2;
	int sum;
	scanf("%d,%d", &num1, &num2);
	sum = Add(num1, num2);
	printf("%d\n", sum);
	system("pause");
	return 0;
}