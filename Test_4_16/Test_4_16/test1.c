#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct Test
{
	short a;
	struct
	{
		double c[10];
		int b;
		//double c;
		char d;
	};
	int e;
}Test;
int main()
{
	printf("%d\n", sizeof(Test));
	system("pause");
	return 0;
}