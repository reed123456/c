#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Max(int x, int y)
{
	if (x > y){
		return x;
	}
	else{
		return y;
	}

}

int main()
{
	int num1, num2;
	int max;
	scanf("%d, %d", &num1, &num2);
	max = Max(num1, num2);
	printf("max = %d\n", max);
	system("pause");
	return 0;
}