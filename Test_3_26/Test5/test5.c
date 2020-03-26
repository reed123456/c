#include <stdio.h>

//abcd = a + b + c + d
int DigitSum(unsigned int n)
{
	int sum = 0;
	if (n > 9)
		return DigitSum(n / 10) + n % 10;
	else
		return n;
}

int main()
{
	unsigned int num;
	scanf("%d", &num);
	printf("%d\n", DigitSum(num));
	system("pause");
	return 0;
}