#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int cash = 20;
	int drinks = cash;
	int emptyBottle = drinks;
	while (emptyBottle > 0 )
	{
			emptyBottle -= 1;
			drinks++;

	}
	printf("drinks = %d\n", drinks);
	system("pause");
	return 0;
}