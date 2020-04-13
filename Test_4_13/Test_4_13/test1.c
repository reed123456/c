#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char *my_strcat(char *dest, const char*src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest++ = *src++))
	{
		;
	}
	return ret;
}

int main()
{
	char str1[20] = "hello world ";
	char str2[] = "heihei";
	printf("%s\n", my_strcat(str1, str2));
	system("pause");
	return 0;
}


//int my_strcmp(const char * src, const char * dest)
//{
//	int ret = 0;
//	assert(src != NULL);
//	assert(dest != NULL);
//	while (!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest)
//	{
//		++src, ++dest;
//	}
//	if (ret < 0)
//		ret = -1;
//	else if (ret > 0)
//		ret = 1;
//	return(ret);
//}
//
//int main()
//{
//	char str1[] = "hello world";
//	char str2[] = "heihei";
//	printf("%d\n", my_strcmp(str1, str2));
//	system("pause");
//	return 0;
//}

//char *my_strcpy(char *dest, const char*src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* temp = dest;
//	while (*temp++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str[20] = "hello world";
//	char *pstr = "heihei";
//	printf("%s\n", my_strcpy(str, pstr));
//	system("pause");
//	return 0;
//}

//int my_strlen(const char * str)
//{
//	assert(str != NULL);
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}
//int main()
//{
//	char str[] = "hello";
//	printf("len = %d\n", my_strlen(str));
//	system("pause");
//	return 0;
//}