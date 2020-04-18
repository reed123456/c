#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char *my_strncpy(char *strDest, const char *strSource, size_t count)
{
	assert(strDest != NULL && strSource != NULL);
	int i;
	for (i = 0; strSource[i] && i < count; i++)
	{
		strDest[i] = strSource[i];
	}

	if (i < count)
	{
		strDest[i] = 0;
	}
	return strDest;
}

int main()
{
	char str[] = "hello";
	char str1[] = "******";
	printf("%s\n", my_strncpy(str, str1, 1));
	system("pause");
	return 0;
}