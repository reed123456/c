#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char input[10] = { 0 };
	int ch;
	scanf("%s", &input);
	//ch = getchar();
	//putchar(ch);
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
	int i = 1;
	printf("%d", i);
	system("pause");
	return 0;
}