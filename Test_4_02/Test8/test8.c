#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void BubbleSort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

void PrintArr(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

//Ã°ÅÝÅÅÐò
int main()
{
	int arr[10] = { 10, 1, 8, 7, 4, 5, 6, 3, 2, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("Ô­Ê¼  Êý×é:");
	PrintArr(arr, sz);
	BubbleSort(arr, sz);
	printf("Ã°ÅÝÅÅÐòºó:");
	PrintArr(arr, sz);
	system("pause");
	return 0;
}
