#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 1;
	double s = 1.0;
	double sum = 0;
	for (n = 1; n <= 100; n++)
	{
		sum += s / n;
		s = -s;
	}
	printf("sum = %lf\n", sum);
	system("pause");
	return 0;
}