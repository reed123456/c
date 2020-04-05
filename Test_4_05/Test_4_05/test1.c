#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);//╤оят
	assert(src != NULL);//╤оят

	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{

	char arr1[20] = "*****************";
	char arr2[] = "hello";
	printf("%s\n", my_strcpy(arr1, arr2));
	system("pause");
	return 0;
}