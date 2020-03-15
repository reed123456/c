#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//typedef unsigned int u_int;
extern int g_val;//声明外部变量
extern int Add(int x, int y);

void test()
{
	static int a = 1;
	a++;
	printf("%d\n", a);
}

int main()
{
	//u_int age;
	int i = 0;
	int a = 12;
	int b = 23;
	while (i < 10){
		test();
		i++;
	}
	printf("g_val = %d\n",g_val);
	printf("%d\n", Add(a, b));
	system("pause");
	return 0;
}