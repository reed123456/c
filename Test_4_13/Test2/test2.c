#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define ROWS 4
#define COLS 4

int findnum(int a[][4], int x, int y, int num)
{
	int i = 0, j = x - 1;

	while (j >= 0 && i < y)
	{
		if (a[i][j] < num)
		{
			i++;
		}
		else if (a[i][j] > num)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	int arr[4][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int n = 11;
	printf("%d\n", findnum(arr, ROWS, COLS, n));
	system("pause");
	return 0;
}