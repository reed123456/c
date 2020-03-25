#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[3][4] = { 1, 2, 3, 4, 5 };
	char arr1[3][5];
	//printf("%d\n", arr[4]);
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d %p\n", arr[i], &arr[i]);
	}
	printf("\n");
	int *p = arr;

	system("pause");
	return 0;
}
/*
int main()
{
	char arr1[] = { 'a', 98, 'c' };
	printf("%d\n", sizeof(arr1));
	char arr2[] = {"abc"};
	printf("%d\n", sizeof(arr2));
	printf("%d\n", strlen(arr1));
	printf("%d\n", strlen(arr2));


	system("pause");
	return 0;
}*/