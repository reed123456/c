#include <stdio.h>

//µÝ¹é
int Fac1(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * Fac1(n - 1);
}

//·ÇµÝ¹é
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
	//µÝ¹é
	int ret1 = Fac1(n);
	printf("%d\n", ret1);
	//·ÇµÝ¹é
	int ret2 = Fac2(n);
	printf("%d\n", ret2);

	system("pause");
	return 0;
}