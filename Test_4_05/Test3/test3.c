#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void alter_order(int* arr, int sz)
{
	assert(arr != NULL);
	int* left = arr;
	int* right = arr + sz - 1;
	while (left < right)
	{
		while (*left % 2 == 1)
		{
			left++;
		}
		while (*right % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int temp = *right;
			*right = *left;
			*left = temp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	while (i < sz)
	{
		scanf("%d", &arr[i++]);
	}

	alter_order(arr, sz);
	
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}