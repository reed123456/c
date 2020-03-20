#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n;
	for (n = 100; n < 201; n++)
	{
		if (n % 2 != 0)
		{
			printf("%d ", n);
		}
	}

	system("pause");
	return 0;
}