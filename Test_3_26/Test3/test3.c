#include <stdio.h>

//�ݹ�
int Fac1(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac1(n - 1);
}

//�ǵݹ�
int Fac2(int n)
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	//�ݹ�
	int ret1 = Fac1(n);
	printf("%d\n", ret1);
	//�ǵݹ�
	int ret2 = Fac2(n);
	printf("%d\n", ret2);

	system("pause");
	return 0;
}