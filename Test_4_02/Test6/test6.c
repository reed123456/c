#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;
	
	for (i = 0; i <= 10000; i++)
	{
		int count = 1;
		int num = i;
		int  sum = 0;
		while (num > 9)
		{
			num = num / 10;
			count++;
		}

		num = i;
		while (num)
		{
			sum += pow(num % 10, count);
			num = num / 10;
		}
		if (sum == i)
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}

//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 999999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//�ж�i�Ƿ�Ϊˮ�ɻ���
//		//1. ���ж����ֵ�λ��
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. ����ÿһλ�Ĵη���
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. �ж�
//		if (sum == i)
//			printf("%d ", i);
//	}
//	system("pause");
//	return 0;
//}