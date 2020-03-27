#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//二维数组的使用
int main()
{
	int arr[3][4] = { { 1, 2 }, { 3, 4 }, { 5 } };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			//printf("%d ", arr[i][j]);
			printf(" arr[%d][%d] = %p ", i, j, &arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}