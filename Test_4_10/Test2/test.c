#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printf("%p\n", arr[0]);
	printf("%p\n", arr);
	printf("%p\n", &arr);

	printf("%p\n", arr[0] + 1);
	printf("%p\n", arr + 1);
	printf("%p\n", &arr + 1);

	system("pause");
	return 0;
}