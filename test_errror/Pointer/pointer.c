#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int* const p1 = &a;
	//p1 = &b;//����
	*p1 = 20;


	const int* p2 = &a;
	p2 = &b;
	//*p2 = 20;//����

	const int* const p3 = &a;
	//p3 = &b;//����
	//*p3 = 20;//����

	printf("a = %d\n", a);
	system("pause");
	return 0;
}