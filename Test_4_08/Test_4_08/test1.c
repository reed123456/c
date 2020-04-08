#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void YangHuiTriangle(int n)
//{
//	int arr[30][30] = { 1 };
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < n; i++)
//	{
//		for (j = 1; j < n; j++)
//		{
//			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
void yangHuiTriangle(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n"); //第一行就直接打印了
	for (i = 1; i < n; i++) //从第二行开始
	{
		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
		{
			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
		}

		for (j = 0; j <= i; j++) //这一行填完就直接打印了。
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}
int main()
{
	int n = 10;
	//scanf("%d", &n);
	yangHuiTriangle(n);
	system("pause");
	return 0;
}