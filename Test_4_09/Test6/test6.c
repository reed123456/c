#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	//函数指针pfun
	void(*pfun)(const char*) = test;
	//函数指针的数组pfunArr
	void(*pfunArr[5])(const char* str);
	pfunArr[0] = test;
	//指向函数指针数组pfunArr的指针ppfunArr
	void(*(*ppfunArr)[10])(const char*) = &pfunArr;
	system("pause");
	return 0;
}