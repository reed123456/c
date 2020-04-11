#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test()
{
	printf("hehe\n");
}
int main()
{
	printf("%p\n", test);
	printf("%p\n", &test);
	system("pause");
	return 0;
}

//int main()
//{
//	/*char str[] = "hello";
//	printf("%d\n", sizeof(str));*/
//	system("pause");
//	return 0;
//}

//a. int a;
//b. int* pa;
//c. int **paa;
//d. int arr[10] ;
//e. int* arr1[10];
//f. int(*arr2)[10];
//g. int(*pfun)(int);
//h. int(*pfun)(int)[10];