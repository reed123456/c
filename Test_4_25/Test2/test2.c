#include <stdio.h>

int main()
{
	int A = 4;
	int B = 6;
	int a = A;
	int b = B;
	int res = 0;
	//scanf("%d %d", &A, &B);
	while (A != 0 && B != 0)
	{
		A = A % B;
		if (A!=0)
			B = B % A;
	}
	res = a * b / (A + B);
	printf("%d\n", res);
	system("pause");
	return 0;
}