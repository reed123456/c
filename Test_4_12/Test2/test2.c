#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void printArray(int *arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int compare(const void * p1 , const void * p2)
{
	return (*(int *)p1 - *(int *)p2);
}

void my_qsort(void *base, size_t count, size_t size, int(*cmp)(const void *, const void *))
{
	char * st = (char *)base;
	char tmp[16];
	for (int i = 0; i< count - 1; i++)
	{
		for (int j = 0; j<count - i - 1; j++)
		{
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				memcpy(tmp, st + j * size, size);
				memcpy(st + j * size, st + (j + 1) * size, size);
				memcpy(st + (j + 1) * size, tmp, size);
			}
		}
	}
}

int main()
{
	int arr[10] = { 2, 3, 4, 5, 0, 1, 7, 9, 8, 6 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, sz);
	my_qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), compare);
	printArray(arr, sz);
	system("pause");
	return 0;
}
