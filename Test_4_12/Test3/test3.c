#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int int_cmp(const void* p1, const void* p2) 
{
	return *((int*)p1) - *((int*)p2);
}

int ch_cmp(const void* p1, const void* p2) 
{
	return *((char*)p1) - *((char*)p2);
}

int str_cmp(const void* p1, const void* p2) 
{
	return strcmp(*((char**)p1), *((char**)p2));
}

int main() {
	int arr[] = { 0, 5, 7, 3, 68, 777 };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), int_cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");


	char ch[] = { 'l', 'i', 'a', 'r' };
	qsort(ch, sizeof(ch) / sizeof(ch[0]), sizeof(ch[0]), ch_cmp);
	for (int i = 0; i < sizeof(ch) / sizeof(ch[0]); i++) {
		printf("%c ", ch[i]);
	}
	printf("\n");


	char* str[] = { "It", "takes", "courage", "to", "believe" };
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), str_cmp);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		printf("%s ", str[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}