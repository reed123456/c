#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("hello world\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i<1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	system("pause");
//	return 0;
//}

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	//按照补码的形式进行运算，最后格式化成为有符号整数
//	system("pause");
//	return 0;
//}
int main()
{
	char a = -128;
	//char a = 128;
	unsigned b = a;
	printf("%u\n", a);
	system("pause");
	return 0;
}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	system("pause");
//	return 0;
//}