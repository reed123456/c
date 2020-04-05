#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//·ÇµÝ¹é
int my_strlen1(const char * str)
{
	int count = 0;
	assert(str != NULL);//¶ÏÑÔ
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//µÝ¹é
int my_strlen2(const char * str)
{
	assert(str != NULL);//¶ÏÑÔ
	if (*str != '\0')
		return 1 + my_strlen2(str+1);
	else
		return 0;
}

int main()
{
	char arr[] = "hello";
	
	//µÝ¹é
	int len1 = my_strlen1(arr);
	printf("len1 = %d\n", len1);

	//·ÇµÝ¹é
	int len2 = my_strlen2(arr);
	printf("len2 = %d\n", len2);

	system("pause");
	return 0;
}