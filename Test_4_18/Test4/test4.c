#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int my_atoi(const char *string)
{
	char* str = string;
	int flag = 1;
	int ret = 0;
	assert(str);

	while (isspace(*str))
	{
		str++;
	}
	if (*str == '\0')
	{
		return 0;
	}

	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}

	while (isdigit(*str))
	{
		ret = ret * 10 + flag * (*str - '0');
		str++;
	}

	if (*str == '\0')
	{
		return ret;
	}
	else
	{
		return ret;
	}
}

int main()
{
	char *str = " -123";
	printf("%d\n", my_atoi(str));
	system("pause");
	return 0;
}