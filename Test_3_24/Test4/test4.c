#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int is_leap_year(int yar)
{
	if ((yar % 4 == 0 && yar % 100 != 0) || (yar %400 == 0))
	{
		return 1;
	}

	return 0;
}
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_leap_year(year) == 1)
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}