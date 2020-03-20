#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int year;
	for (year = 1000; year < 2001; year++)
	{
		if (year % 100 == 0)
		{
			if (year % 4 == 0)
			{
				printf("%d ", year);
			}
		}
		else
		{
			if (year % 4 == 0)
			{
				printf("%d ", year);
			}
		}
	}
	system("pause");
	return 0;
}