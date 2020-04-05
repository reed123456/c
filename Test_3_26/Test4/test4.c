#include <stdio.h>
#include <string.h>
#include <assert.h>

int my_strlen(const char * str)
{
	assert(str != NULL);//����
	if (*str != '\0')
		return 1 + my_strlen(str+1);
	else
		return 0;
}

//�ǵݹ�
char* my_strrev1(const char* str)
{
	assert(str != NULL);//����
	char *left = str;
	char *right = str + my_strlen(str) - 1;

	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}
	return str;
}

//�ݹ�
void my_strrev2(char* str)
{
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);

	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
		my_strrev2(str + 1);

	*(str + len - 1) = tmp;
}

int main()
{
	char str1[] = "hello world";
	char str2[] = "alice";
	printf("ԭ�ַ�����%s\n", str1);
	//my_strrev1(str1);
	printf("  �����%s\n", my_strrev1(str1));

	printf("\nԭ�ַ�����%s\n", str2);
	my_strrev2(str2);
	printf("  �����%s\n", str2);
	system("pause");
	return 0;
}