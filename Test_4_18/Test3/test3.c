#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>

char *my_strncat(char *strDest, const char *strSource, size_t count)
{
	assert(strDest != NULL && strSource != NULL);
	char * tmp = strDest;

	while (*strDest)
	{
		strDest++;
	}

	int i;
	for (i = 0; strSource[i] && i < count; i++)
	{
		strDest[i] = strSource[i];
	}

	strDest[i] = 0;
	return tmp;
}

int main()
{
	char str1[20] = "hello ";
	char str2[] = "world";
	printf("%s\n", my_strncat(str1, str2, 5));
	system("pause");
	return 0;
}