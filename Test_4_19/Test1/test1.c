#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[10] = {0};
	int sz = sizeof(arr) / sizeof(arr[0]);
	FILE *fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "r");
	if (NULL == fp)
	{
		printf("Open file failer.");
		return;
	}
	fread(arr, sizeof(int), sz, fp);
	/*for (int i = 0; i < sz; i++)
	{
		fscanf(fp, "%d", arr[i]);
	}*/
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	fclose(fp);
	system("pause");
	return 0;
}


#include <stdio.h>
int main()
{
	FILE * pFile;//文件指针变量
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL)
	{
		fputs("fopen example", pFile);
		fclose(pFile);
	}
	return 0;
}