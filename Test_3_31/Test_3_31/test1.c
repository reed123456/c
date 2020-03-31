#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fun()
{
	static int count = 1;
	return ++count;
}
int main()
{
	//int a = 0;
	//{
	//	int a = 0;
	//}
	//printf("%d\n", a);
	//int arr[] = { 1, 2, (3, 4, 5), 6 };
	//printf("%d\n", sizeof(arr));
	int sum = fun() + fun() - fun()*fun();
	printf("%d\n", sum);
	system("pause");
	return 0;
}