#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

#include <stdio.h>
int add(int a, int b){ return a + b; }
int sub(int a, int b){ return a - b; }
int mul(int a, int b){ return a * b; }
int div(int a, int b){ return a / b; }
int main()
{
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div }; //函数指针数组/转移表
	return 0;
}



//char *my_strcpy(char *dest, const char*src)//指针函数
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* temp = dest;
//	while (*temp++ = *src++)
//	{
//		;
//	}
//	return dest;
//}
//
//int main()
//{
//	char str[20] = "hello world";
//	char *pstr = "heihei";
//
//	char* (*pfun)(char, const char*) = my_strcpy;//pfun-->函数指针
//	printf("%s\n", pfun(str, pstr));
//	system("pause");
//	return 0;
//}



//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//	int *parr[4] = { &a, &b, &c, &d };//parr-->指针数组
//
//	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*parr1)[10] = &arr1;//parr1-->数组指针
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 10; 
//	int b = 20;
//	int* pa = &a;//pa-->一级指针
//	int* ppa = &pa;//ppa-->二级指针
//	system("pause");
//	return 0;
//}
//+&a	0x0073fa64 {16089424}	int *
//+		&b	0x006ffd88 {20}	int *
//+		&pa	0x006ffd7c {0x006ffd94 {10}}	int * *
//+		&ppa	0x006ffd70 {0x006ffd7c {7339412}}	int * *
