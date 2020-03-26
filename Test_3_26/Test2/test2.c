#include <stdio.h>

int Fun(int n)
{
	if (n == 5)
		return 2;
	else
		return 2 * Fun(n + 1);
}

int main()
{
	int ret = Fun(2);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}