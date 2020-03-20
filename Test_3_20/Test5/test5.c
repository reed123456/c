#include <stdio.h>

int main()
{
	int n;
	int a, b;
	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	n = (a < b) ? a : b;

	if (a == 0 || b == 0)
	{
		printf("最大公约数:%d\n", n);
	}
	else
	{
		while (a % n != 0 || b % n != 0)
		{
			n--;
		}
		printf("最大公约数:%d\n", n);
	}

	system("pause");
	return 0;
}