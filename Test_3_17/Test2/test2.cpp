#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

int main()
{
	int arr[10] = { 0 };
	int i, size;
	size = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < size; i++){
		arr[i] = i;
	}
	for (i = 0; i < size; i++){
		printf("arr[%d] = %d\n", arr[i], arr[i]);
	}
	system("pause");
	return 0;
}