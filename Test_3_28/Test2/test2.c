#include <stdio.h>
#include <string.h>


void fun(int *str)//str为首元素地址
{
	printf("%d\n", sizeof(str));//-->1
	printf("%d\n", strlen(str));//-->4 strlen()找的是'\0'
}

int main()
{
	printf("%d\n", strlen("hello"));//-->5
	//size(char) = 1, 因此计算字符串大小时可省略·
	printf("%d\n", sizeof("hello"));//-->6

	char str = "moon";
	printf("%d\n", sizeof(str));//-->6   传递的是数组的地址
	fun(str);
}



//int fun1(int* arr, int sz)
//{
//
//}
//
//void main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	fun1(arr);
//}
//
//
//void fun2(int* arr)
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
//	fun2(arr);
//}
//
//
//
//
//
//
//
//
//


//int main()
//{
//	char str1[] = "hello";
//	char str2[] = { 'h', 'e', 'l', 'l', 'o' };
//	char str3[10] = { 'h', 'e', 'l', 'l', 'o', '\0' };
//	printf("strlen(str1)：%d\n", strlen(str1));
//	printf("strlen(str2)：%d\n", strlen(str2));
//	printf("strlen(str3)：%d\n", strlen(str3));
//	system("pause");
//	return 0;
//}
//
//struct person
//{
//	char name[10];
//	int age;
//	char sex[5];
//};
//int main()
//{
//	int arr[10] = { 0 };
//	double a = 10.0;
//	printf("sizeof(int) : %d\n", sizeof(int));
//	printf("sizeof(int *) : %d\n", sizeof(int *));
//	printf("sizeof(a) :%d\n", sizeof a);
//	printf("sizeof(arr) : %d\n", sizeof(arr));
//	printf("sizeof(arr)/sizeof(arr[0])) : %d\n", sizeof(arr)/sizeof(arr[0]));
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello";
//	char str2[] = { 'h', 'e', 'l', 'l', '0', '\0' };
//	char str3[10] = { 'h', 'e', 'l', 'l', '0', '\0' };
//	printf("sz-str1：%d\n", sizeof(str1) / sizeof(str1[0]));
//	printf("strlen(str1)：%d\n",strlen(str1));
//	printf("sz-str2：%d\n", sizeof(str2) / sizeof(str2[0]));
//	printf("strlen(str2)：%d\n", strlen(str1));
//	printf("sz-str3：%d\n", sizeof(str3) / sizeof(str3[0]), strlen(str3));
//	printf("strlen(str3)：%d\n", sizeof(str3) / sizeof(str3[0]), strlen(str3));
//	system("pause");
//	return 0;
//}