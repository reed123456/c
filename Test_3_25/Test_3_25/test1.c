#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void mutltiplication_table(int n)
{
	printf("%d * %d ³Ë·¨¿Ú¾÷±í\n", n, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (n < 10)
				printf("%d*%d=%-5d", i, j, i *j);
			else
				printf("%-2d*%-2d=%-5d", i, j, i *j);
		}
		printf("\n");
	}
}
int main()
{
	int input;
	scanf("%d", &input);
	mutltiplication_table(input);
	system("pause");
	return 0;
}