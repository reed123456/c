#include <stdio.h>

int main()
{
	int n = 9;
	printf("%30d * %d ³Ë·¨¿Ú¾÷±í\n", n, n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d   ", i, j, i *j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}