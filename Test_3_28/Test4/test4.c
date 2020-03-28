#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Swap(int *arr1, int *arr2, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

void Print(int  * arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 11, 12, 13 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);

	Swap(arr1, arr2, sz);
	printf("arr1:");
	Print(arr1, sz);
	printf("arr2:");
	Print(arr2, sz);

	system("pause");
	return 0;
}