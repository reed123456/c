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
	printf("1\n"); //��һ�о�ֱ�Ӵ�ӡ��
	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ
	{
		for (j = i; j > 0; j--) //�Ӻ���ǰ�������һ�е�������ʹ��ǰ�ͱ�����
		{
			data[j] += data[j - 1]; //��ʽͬ�ϣ����ڱ����һά����ʽҲ����ˡ�
		}

		for (j = 0; j <= i; j++) //��һ�������ֱ�Ӵ�ӡ�ˡ�
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