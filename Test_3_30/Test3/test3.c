#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int calc_bit_1(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

int main()
{
	int input;
	scanf("%d", &input);
	printf("%d\n", calc_bit_1(input));
	system("pause");
	return 0;
}