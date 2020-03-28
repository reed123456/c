#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX_SIZE 10

void Init(int  * arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void Reverse(int * arr, int sz)
{
	
	char *left = arr;
	char *right = arr + sz - 1;

	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}
}

void Print(int  * arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[MAX_SIZE];
	int sz = MAX_SIZE;

	//��ʼ������
	Init(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
	
	//��������
	Reverse(arr, sz);
	//��ӡ����
	Print(arr, sz);
	system("pause");
	return 0;
}