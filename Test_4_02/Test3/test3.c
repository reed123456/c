#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void PrintArr(int *arr, int sz)
{
	int *left = arr;
	int *right = arr + sz;

	while (left < right)
	{
		printf("%d ", *left);
		left++;
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	PrintArr(arr, sz);
	system("pause");
	return 0;
}