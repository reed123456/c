#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//二进制写
	FILE *fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "wb");
	if (NULL == fp)
	{
		printf("Open file failer.");
		return;
	}
	fwrite(arr, sizeof(int), sz, fp);

	//文本写
	/*
	FILE *fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "w");
	if (NULL == fp)
	{
		printf("Open file failer.");
		return;
	}
	for (int i = 0; i < sz; i++)
	{
		fprintf(fp, "%d ", arr[i]);
	}
	fclose(fp);
	*/
	system("pause");
	return 0;
}