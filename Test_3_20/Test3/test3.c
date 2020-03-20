#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fun(int a)
{
	int b;
	switch (a)
	{
	case 1:
		b = 30;
	case 2:
		b = 20;
	case 3:
		b = 10;
	default:
		b = 0;
	}
	return b;
}
/*
int main()
{
	printf("%d", fun(1));
	system("pause");
	return 0;
}*/
#include <stdio.h>
int main() {
	int x = 3;
	int y = 3;
	switch (x % 2) {
	case 1:
		switch (y)
		{
		case 0:
			printf("first");
		case 1:
			printf("second");
			break;
		default: printf("hello");
		}
	case 2:
		printf("third");
	}
	system("pause");
	return 0;
}