#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int num;
	int count = 0;
	for (num = 0; num <= 100; num++)
	{
		if (num % 10 == 9)
		{
			count++;
		}
		
		if (num / 10 == 9)
		{
			count++;
		}
	}
	printf("count = %d\n", count);

	system("pause");
	return 0;
}