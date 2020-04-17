#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#pragma pack(4)

typedef struct{
	int a;//4
	char b;//2
	short c;//2
	short d;//2
}AA_t;


struct A
{
	int a;//4
	short b;//2 + 2
	int c;//4
	char d;//1 + 3
};
struct B
{
	int a;//4
	short b;//2
	char c;//1 + 1
	int d;//4
};
int main()
{
	printf("size AA_t = %d\n", sizeof(AA_t));
	printf("size A = %d\n", sizeof(struct A));
	printf("size B = %d\n", sizeof(struct B));
	system("pause");
	return 0;
}