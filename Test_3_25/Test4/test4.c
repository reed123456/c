#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�ǵݹ�
int my_strlen1(char * str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//�ݹ�
int my_strlen2(char * str)
{
	if (*str != '\0')
		return 1 + my_strlen2(str+1);
	else
		return 0;
}

int main()
{
	char arr[] = "bit";
	
	//�ݹ�
	int len1 = my_strlen1(arr);
	printf("%d\n", len1);

	//�ǵݹ�
	int len2 = my_strlen2(arr);
	printf("%d\n", len2);

	system("pause");
	return 0;
}