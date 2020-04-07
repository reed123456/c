#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	/*unsigned int a = 0x1234;
	unsigned char b = *(unsigned char *)&a;
	printf("%d", b);*/
	char a[1000] = { 0 };
	int i = 0;
	for (i = 0; i < 1000; i++ )
	{
		a[i] = -1 - i;
	}
	printf("%d\n", strlen(a));
	system("pause");
	return 0;
}