#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	//����ָ��pfun
	void(*pfun)(const char*) = test;
	//����ָ�������pfunArr
	void(*pfunArr[5])(const char* str);
	pfunArr[0] = test;
	//ָ����ָ������pfunArr��ָ��ppfunArr
	void(*(*ppfunArr)[10])(const char*) = &pfunArr;
	system("pause");
	return 0;
}