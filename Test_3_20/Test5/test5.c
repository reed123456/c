#include <stdio.h>

int main()
{
	int n;
	int a, b;
	printf("����������������");
	scanf("%d %d", &a, &b);
	n = (a < b) ? a : b;

	if (a == 0 || b == 0)
	{
		printf("���Լ��:%d\n", n);
	}
	else
	{
		while (a % n != 0 || b % n != 0)
		{
			n--;
		}
		printf("���Լ��:%d\n", n);
	}

	system("pause");
	return 0;
}