#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	double a1[5] = { 66.8, 57.2, 78.0, 70.0, 67.4 };
	double a2[5] = { 75.6, 66.0, 67.8, 74.2, 71.0 };
	double a3[5] = { 87.0, 66.4, 84.6, 69.6, 83.8 };
	double a4[5] = { 58.6, 53.0, 59.4, 57.2, 62.4 };

	int n = 0;
	double sum = 0, best = 0;

	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == i)
				continue;
			for (int k = 0; k<5; k++)
			{
				if (k == j || k == i)
					continue;
				for (int m = 0; m<5; m++)
				{
					if (m == k || m == j || m == i)
						continue;

					printf("蝶泳=%lf,蛙泳=%lf,自由泳=%lf", a1[i], a2[j], a3[k], a4[m]);
					sum = a1[i] + a2[j] + a3[k] + a4[m];
					printf("总成绩为=%lf\n", sum);

					if (best<sum&&best != 0)
						best = best;
					else 
						best = sum;
				}
			}
		}
	}
	printf("最优解为：%lf\n", best);

	system("pause");
	return 0;
}