#include <stdio.h>
#include <string.h>

int my_strlen(char * str)
{
	if (*str != '\0')
		return 1 + my_strlen(str+1);
	else
		return 0;
}
/*
void reverse_string(char* arr)
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
}*/

void reverse_string(char* arr)
{
	int len = my_strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);

	*(arr + len - 1) = '\0';
	if (strlen(arr + 1) >= 2)
		reverse_string(arr + 1);

	*(arr + len - 1) = tmp;
}

int main()
{
	char arr[] = "hello bit.";
	printf("%d\n", strlen("bit"));
	reverse_string(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}