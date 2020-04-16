#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char *strstr(const char *string, const char *strCharSet)
{
	assert(string != NULL);
	assert(string != NULL);
	char *pstr = (char*)string;
	char *substr = (char *)strCharSet;
	char *s1 = NULL;

	if (*strCharSet == '\0')
		return NULL;

	while (*pstr)
	{
		s1 = pstr;
		substr = strCharSet;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return pstr;
		pstr++;
	}
}

int main()
{
	char str[] = "This is a test string";
	char substr[] = "is";
	char *pstr = strstr(str, substr);
	printf("%s\n", str);
	printf("%s\n", pstr);
	system("pause");
	return 0;
}