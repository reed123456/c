#include <stdio.h>

int Power(int num, int k)
{
	if (k > 1)
		return Power(num, k - 1) * num;
	else
	return num;
}

int main()
{
	int num;
	int k;
	scanf("%d %d", &num, &k);
	printf("%d\n", Power(num, k));
	system("pause");
	return 0;
}