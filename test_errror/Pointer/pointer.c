#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int* const p1 = &a;
	//p1 = &b;//´íÎó
	*p1 = 20;


	const int* p2 = &a;
	p2 = &b;
	//*p2 = 20;//´íÎó

	const int* const p3 = &a;
	//p3 = &b;//´íÎó
	//*p3 = 20;//´íÎó

	printf("a = %d\n", a);
	system("pause");
	return 0;
}