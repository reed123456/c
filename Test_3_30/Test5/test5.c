#include <stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	printf("����ǰ:a = %d b = %d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("������:a = %d b = %d\n", a, b);
	system("pause");
	return 0;
}