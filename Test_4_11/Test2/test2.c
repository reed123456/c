#include <stdio.h>

int main()
{
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a));//48
	printf("%d\n", sizeof(a[0][0]));//4
	printf("%d\n", sizeof(a[0]));//16
	printf("%d\n", sizeof(a[0] + 1));//4
	printf("%d\n", sizeof(*(a[0] + 1)));//4
	printf("%d\n", sizeof(a + 1));//4
	printf("%d\n", sizeof(*(a + 1)));//16
	printf("%d\n", sizeof(&a[0] + 1));//4
	printf("%d\n", sizeof(*(&a[0] + 1)));//16
	printf("%d\n", sizeof(*a));//16
	printf("%d\n", sizeof(a[3]));//16
	system("pause");
	return 0;
}

//----------------------------------------------------------------------
//int main()
//{
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4
//	printf("%d\n", sizeof(p + 1));//4
//	printf("%d\n", sizeof(*p));//1
//	printf("%d\n", sizeof(p[0]));//1
//	printf("%d\n", sizeof(&p));//4
//	printf("%d\n", sizeof(&p + 1));//4
//	printf("%d\n", sizeof(&p[0] + 1));//4
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//error
//	//printf("%d\n", strlen(p[0]));//error
//	printf("%d\n", strlen(&p));//...
//	printf("%d\n", strlen(&p + 1));//...
//	printf("%d\n", strlen(&p[0] + 1));//5
//	system("pause");
//	return 0;
//}

//----------------------------------------------------------------------
//int main()
//{
//	char arr[] = "abcdef";
//
//	printf("%d\n", sizeof(arr));//7
//	printf("%d\n", sizeof(arr + 0));//4
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4
//	printf("%d\n", sizeof(&arr + 1));//4
//	printf("%d\n", sizeof(&arr[0] + 1));//4
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	printf("%d\n", strlen(*arr));//error
//	printf("%d\n", strlen(arr[1]));//error
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//...
//	printf("%d\n", strlen(&arr[0] + 1));//5
//
//	system("pause");
//	return 0;
//}

//----------------------------------------------------------------------
//int main()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr));//6
	//printf("%d\n", sizeof(arr + 0));//4
	//printf("%d\n", sizeof(*arr));//1
	//printf("%d\n", sizeof(arr[1]));//1
	//printf("%d\n", sizeof(&arr));//4
	//printf("%d\n", sizeof(&arr + 1));//4
	//printf("%d\n", sizeof(&arr[0] + 1));//4
	//printf("%d\n", strlen(arr));//...
	//printf("%d\n", strlen(arr + 0));//...
	//printf("%d\n", strlen(*arr));//error
	//printf("%d\n", strlen(arr[1]));//error
	//printf("%d\n", strlen(&arr));//...
	//printf("%d\n", strlen(&arr + 1));//...
	//printf("%d\n", strlen(&arr[0] + 1));//...
//	system("pause");
//	return 0;
//}
//----------------------------------------------------------------------
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//16
//	printf("%d\n", sizeof(a + 0));//4
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//4
//	printf("%d\n", sizeof(*&a));//16?
//	printf("%d\n", sizeof(&a + 1));//4
//	printf("%d\n", sizeof(&a[0]));//4
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	system("pause");
//	return 0;
//}
//----------------------------------------------------------------------