#include"sort.h"

#define MAX_Size 9
void TestSort(int* ar, int n); 
void TestSortEfficiency();
void PrintElement(int *elem, int sz);

int main()
{
	int ar[] = { 49, 38, 5, 65, 97, 76, 13, 27, 49 };
	int n = sizeof(ar) / sizeof(ar[0]);
	TestSort(ar, n);
	TestSortEfficiency();
	system("pause");
	return 0;
}

void TestSort(int* ar, int n)
{
	int ar1[MAX_Size], ar2[MAX_Size], ar3[MAX_Size], ar4[MAX_Size],
		ar5[MAX_Size], ar6[MAX_Size], ar7[MAX_Size], ar8[MAX_Size];
	for (int i = 0; i < n; ++i)
	{
		ar1[i] = ar[i];
		ar2[i] = ar[i];
		ar3[i] = ar[i];
		ar4[i] = ar[i];
		ar5[i] = ar[i];
		ar6[i] = ar[i];
		ar7[i] = ar[i];
		ar8[i] = ar[i];
	}
	printf("ar : ");
	PrintElement(ar, n);
	printf("\n对数组 ar 中的数据进行排序\n");

	printf("   InsertSort : ");
	InsertSort(ar1, 0, n);
	PrintElement(ar1, n);

	printf("BinInsertSort : ");
	BinInsertSort(ar2, 0, n);
	PrintElement(ar2, n);

	printf("    ShellSort : ");
	ShellSort(ar3, 0, n);
	PrintElement(ar3, n);

	printf("   SelectSort : ");
	SelectSort(ar4, 0, n);
	PrintElement(ar4, n);

	printf("     HeapSort : ");
	HeapSort(ar5, 0, n);
	PrintElement(ar5, n);

	printf("   BubbleSort : ");
	BubbleSort(ar6, 0, n);
	PrintElement(ar6, n);

	printf("    QuickSort : ");
	QuickSort(ar7, 0, n);
	PrintElement(ar7, n);

	printf("    MergeSort : ");
	MergeSort(ar8, 0, n);
	PrintElement(ar8, n);
}

void TestSortEfficiency()
{
	int n = 2000;
	int *a1 = (int *)malloc(sizeof(int)* n);
	int *a2 = (int *)malloc(sizeof(int)* n);
	int *a3 = (int *)malloc(sizeof(int)* n);
	int *a4 = (int *)malloc(sizeof(int)* n);
	int *a5 = (int *)malloc(sizeof(int)* n);
	int *a6 = (int *)malloc(sizeof(int)* n);
	int *a7 = (int *)malloc(sizeof(int)* n);
	int *a8 = (int *)malloc(sizeof(int)* n);

	srand(time(0));
	for (int i = 0; i<n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	printf("\n排序 %d 个数所需要的时间(单位/ms).\n", n);
	time_t start = clock();
	InsertSort(a1, 0, n);
	time_t end = clock();
	printf("   InsertSort : %u\n", end - start);

	start = clock();
	BinInsertSort(a2, 0, n);
	end = clock();
	printf("BinInsertSort : %u\n", end - start);

	start = clock();
	ShellSort(a3, 0, n);
	end = clock();
	printf("    ShellSort : %u\n", end - start);

	start = clock();
	SelectSort(a4, 0, n);
	end = clock();
	printf("   SelectSort : %u\n", end - start);

	start = clock();
	HeapSort(a5, 0, n);
	end = clock();
	printf("     HeapSort : %u\n", end - start);

	start = clock();
	BubbleSort(a6, 0, n);
	end = clock();
	printf("   BubbleSort : %u\n", end - start);

	start = clock();
	QuickSort(a7, 0, n);
	end = clock();
	printf("     QuickSort: %u\n", end - start);

	start = clock();
	MergeSort(a8, 0, n);
	end = clock();
	printf("    MergeSort : %u\n", end - start);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
}

void PrintElement(int *elem, int sz)
{
	for (int i = 0; i<sz; ++i)
		printf("%d ", elem[i]);
	printf("\n");
}