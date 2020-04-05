#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

//�ǵݹ�
int my_strlen1(const char * str)
{
	int count = 0;
	assert(str != NULL);//����
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//�ݹ�
int my_strlen2(const char * str)
{
	assert(str != NULL);//����
	if (*str != '\0')
		return 1 + my_strlen2(str+1);
	else
		return 0;
}

int main()
{
	char arr[] = "hello";
	
	//�ݹ�
	int len1 = my_strlen1(arr);
	printf("len1 = %d\n", len1);

	//�ǵݹ�
	int len2 = my_strlen2(arr);
	printf("len2 = %d\n", len2);

	system("pause");
	return 0;
}