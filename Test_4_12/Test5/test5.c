#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>

char * leftRound(char* src, int n)
{
	assert(src != NULL);
	int len = strlen(src);
	int i, j;
	for (i = 0; i < n; ++i)
	{
		char temp = src[0];
		for (j = 0; j < len; ++j)
		{
			src[j] = src[j + 1];
		}
		src[len-1] = temp;
	}
	return src;
}

int main()
{
	char str[] = "hello world";
	printf("%s\n", leftRound(str, 1));
	system("pause");
	return 0;
}