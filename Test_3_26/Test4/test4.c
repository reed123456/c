#include <stdio.h>
#include <string.h>

int my_strlen(char * str)
{
	if (*str != '\0')
		return 1 + my_strlen(str+1);
	else
		return 0;
}

//�ǵݹ�
char * my_strrev1(char* arr)
{
	char *left = arr;
	char *right = arr + my_strlen(arr) - 1;

	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;

		left++;
		right--;
	}
	return arr;
}

//�ݹ�
void my_strrev2(char* arr)
{
	int len = my_strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);

	*(arr + len - 1) = '\0';
	if (strlen(arr + 1) >= 2)
		my_strrev2(arr + 1);

	*(arr + len - 1) = tmp;
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