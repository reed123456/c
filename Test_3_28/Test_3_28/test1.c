#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, (3, 4), 5 };
	printf("%d\n", sizeof(arr));
	system("pause");
	return 0;
}