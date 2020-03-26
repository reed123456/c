#include <iostream>
#define M 3
#define N 5
int main()
{
	int tj;
	int arr[M][N] = { 1, 2, 0, 49, 5,
		              6, 7, 8, 7, 10, 
		             11, 9, 13, 14, 15 };
	for (int i = 0; i < M; i++)
	{
		int min = arr[i][0];
		for (int j = 0; j < N; j++)
		{
			if (min > arr[i][j])
			{
				min = arr[i][j];
				tj = j;
			}
		}
		for (int k = 0; k < M; k++)
		{
			if (min < arr[k][tj])
				min = arr[k][tj];
		}
		if (min == arr[i][tj])
			printf("arr[%d][%d] = %d\n", i, tj, arr[i][tj]);
	}

	system("pause");
	return 0;
}