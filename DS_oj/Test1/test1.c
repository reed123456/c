#include <stdio.h>
#include <malloc.h>

#define ROW 5
#define COL 5

int main()
{
	int **ppa = (int *)malloc(sizeof(int)* ROW);
	for (int i = 0; i < ROW; i++)
	{
		ppa[i] = (int *)malloc(sizeof(int)* COL);
	}

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			ppa[i][j] = i * j;
		}
	}

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			printf("%d ", ppa[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < ROW; i++)
	{
		free(ppa[i]);
	}
	free(ppa);
	
	system("pause");
	return 0;
}