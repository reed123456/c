#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void Reserve(char *str)
{
	char *left = str;
	char *right = str + strlen(str) - 1;

	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		++left;
		--right;
	}
}


int main()
{
	char str[] = "hello bit.";
	Reserve(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}