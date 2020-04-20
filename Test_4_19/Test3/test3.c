#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//#define SWAP_ODD_EVEN(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)
#define SwapIntBit(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)
#define offsetof(StructType, MemberName) (size_t)&(((StructType *)0)->MemberName

typedef struct Test
{
	int a;
	char b;
	double c;
}Test;
int main()
{
	Test test = { 0, 0, 'a' };
	int n = 13;
	int ret = SwapIntBit(n);
	printf("%d\n", ret);

	/*offsetof(test, test.a)*/
	system("pause");
	return 0;
}



/*
#define INT_PTR int*
typedef int*int_ptr;

int main()
{
	INT_PTR a, b;
	int_ptr c, d;
}

/*
设有以下宏定义:

#define N 4

#define Y(n) ((N+2)*n) /*这种定义在编程规范中是严格禁止的

则执行语句：z = 2 * (N + Y(5 + 1)); 后，z的值为
         z = 2 * (4 + (4 + 2) *5 + 1)
		   =  2 * (4 + 6 * 5 + 1)
		   = 2 * 35
		   = 70
*/