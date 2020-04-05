#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void my_strrev(char* str)
{
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);

	*(str + len - 1) = '\0';
	if (strlen(str + 1) >= 2)
		my_strrev(str + 1);

	*(str + len - 1) = tmp;
}

int main()
{
	char str1[] = "hello world";
	char str2[] = "alice";
	printf("Ô­×Ö·û´®£º%s\n", str1);
	my_strrev(str1);
	printf("  ÄæÐòºó£º%s\n", my_strrev1(str1));

	printf("\nÔ­×Ö·û´®£º%s\n", str2);
	my_strrev(str2);
	printf("  ÄæÐòºó£º%s\n", str2);
	system("pause");
	return 0;
}