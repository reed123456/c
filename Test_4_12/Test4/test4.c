#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int findRound(const char * src, char * find)
{
	char tmp[256] = { 0 }; 
	strcpy(tmp, src); 
	strcat(tmp, src);
	return strstr(tmp, find) != NULL; 
}

int main()
{
	char str1[] = "AABCD";
	char str2[] = "BCDAA";
	if (findRound(str1, str2))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
	return 0;
}