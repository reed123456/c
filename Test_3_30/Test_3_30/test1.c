#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int get_diff_bit(int m, int n)
{
	int count = 0;
	int temp = m^n;
	while (temp)
	{
		temp = temp&(temp - 1);
		count++;
	}
	return count;
}

int main()
{
	int m;
	int n;
	printf("请输入两个整数:>");
	scanf("%d %d", &m, &n);
	printf("diff = %d\n", get_diff_bit(m, n));
	system("pause");
	return 0;
}