#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float h = 0.0002;
	float H = 8848.48;
	int count = 0;
	while (h <= H)
	{
		h *= 2;
		count++;
	}
	printf("h:%f\n", h);
	printf("count = %d\n", count);

	system("pause");
	return 0;
}