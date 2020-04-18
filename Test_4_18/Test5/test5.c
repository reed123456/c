#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void findSingal(int* arr, int sz, int * pnum)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 1;
		for (j = 0; j < sz; j++)
		{
			if (arr[i] == arr[j] && i != j)
				flag = 2;
		}
		if (flag == 1)
			pnum[k++] = arr[i];
		if (k == 2)
			break;
	}
}

int main()
{
	int num[2];
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	findSingal(arr, sz, num);
	printf("%d, %d\n", num[0], num[1]);
	system("pause");
	return 0;
}