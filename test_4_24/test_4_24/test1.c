#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
enum Day//ÐÇÆÚ
{
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};
int main()
{
	printf("%d\n", sizeof(enum Day));
	int arr[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	int (*parr)[4] = &arr;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%-2d ", parr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

/*
void Swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

int main()
{
	int a = 10;
	int b = 20;
	printf("a= %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("a= %d, b = %d\n", a, b);
	system("pause");
	return 0;
}*/