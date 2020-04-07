#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void yangHuiTriangle(int n)
{
	int data[30][30] = { 1 }; //第一行直接填好，播下种子

	int i, j;

	for (i = 1; i < n; i++) //从第二行开始填
	{
		data[i][0] = 1; //每行的第一列都没有区别，直接给1，保证不会越界。
		for (j = 1; j <= i; j++) //从第二列开始填
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1]; //递推方程
		}
	}

	for (i = 0; i < n; i++) //填完打印
	{
		for (j = 0; j <= i; j++)
		{
			printf("%-3d ", data[i][j]);
		}
		putchar('\n');
	}
}


int main()
{
	int n = 10;
	yangHuiTriangle(n);
	system("pause");
	return 0;
}