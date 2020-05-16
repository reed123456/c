#ifndef _HEAP_H_
#define _HEAP_H_

#include"common.h"
#define HeapDataType int

typedef struct Heap
{
	HeapDataType *base;
	int           capacity;
	int           size;
}Heap;

void HeapInit(Heap *php, int n);
bool HeapEmpty(Heap *php);
void MinHeapPrint(Heap *php);

//小堆
void MinHeapInsert(Heap *php, HeapDataType x);
HeapDataType MinHeapRemove(Heap *php);
void MinAdjustUp(HeapDataType *base, int start);
void MinAdjustDown(HeapDataType *base, int start, int n);
void MinHeapSort(Heap *php);

//大堆
void MaxHeapInsert(Heap *php, HeapDataType x);
HeapDataType MaxHeapRemove(Heap *php);
void MaxAdjustUp(HeapDataType *base, int start);
void MaxAdjustDown(HeapDataType *base, int start, int n);
void MaxHeapSort(Heap *php, int ar[], int n);


//初始化
void HeapInit(Heap *php, int n)
{
	assert(php != NULL);
	php->base = (HeapDataType*)malloc(sizeof(HeapDataType)* n);
	assert(php->base != NULL);
	php->capacity = n;
	php->size = 0;
}

bool HeapEmpty(Heap *php)
{
	assert(php != NULL);
	return php->size == 0;
}

//插入元素
void MinHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;

		//调整为小堆结构  从下往上调整
		MinAdjustUp(php->base, php->size);
		php->size++;
	}
}

//小堆调整
HeapDataType MinHeapRemove(Heap *php)
{
	assert(php != NULL);
	assert(php->size > 0);

	int heaptop_val = php->base[0];

	php->size--;
	php->base[0] = php->base[php->size];
	MinAdjustDown(php->base, 0, php->size);

	return heaptop_val;
}

void HeapPrint(Heap *php)
{
	for (int i = 0; i<php->size; ++i)
		printf("%d ", php->base[i]);
	printf("\n");
}

//向上插入
void MinAdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapDataType tmp = base[j];

	while (j > 0)
	{
		if (tmp < base[i])
		{
			base[j] = base[i]; //覆盖
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	base[j] = tmp;
}



//向下插入
void MinAdjustDown(HeapDataType *base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && base[j]>base[j + 1]) //找出左右子树较小的值
			j++;
		if (base[i] > base[j])
		{
			Swap(&base[i], &base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

//堆排序
void MinHeapSort(Heap *php, int ar[], int n)
{
	for (int i = 0; i<n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//调整成小堆
	int curpos = n / 2 - 1; //找到最后一个分支
	while (curpos >= 0)
	{
		MinAdjustDown(php->base, curpos, n);
		curpos--;
	}

	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&php->base[0], &php->base[end]);
		MinAdjustDown(php->base, 0, end);
		end--;
	}
	//HeapPrint(php);
	int k = php->size - 1;
	for (int i = 0; i<n; ++i)
	{
		ar[i] = php->base[k--];
	}
}

/*
void AdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j-1)/2;
	while(j > 0)
	{
		if(base[j] < base[i])
		{
		Swap(&(base[j]), &(base[i]));
		j = i;
		i = (j-1)/2;
		}
		else
			break;
	}
}
*/
//大堆
//插入元素
void MaxHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;

		//调整为小堆结构  从下往上调整
		MaxAdjustUp(php->base, php->size);
		php->size++;
	}
}

//小堆调整
HeapDataType MaxHeapRemove(Heap *php)
{
	assert(php != NULL);
	assert(php->size > 0);

	int heaptop_val = php->base[0];

	php->size--;
	php->base[0] = php->base[php->size];
	MaxAdjustDown(php->base, 0, php->size);

	return heaptop_val;
}

//向上插入
void MaxAdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapDataType tmp = base[j];

	while (j > 0)
	{
		if (tmp > base[i])
		{
			base[j] = base[i]; //覆盖
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	base[j] = tmp;
}



//向下插入
void MaxAdjustDown(HeapDataType *base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && base[j]<base[j + 1]) //找出左右子树较小的值
			j++;
		if (base[i] < base[j])
		{
			Swap(&base[i], &base[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}

//堆排序
void MaxHeapSort(Heap *php, int ar[], int n)
{
	for (int i = 0; i<n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//调整成小堆
	int curpos = n / 2 - 1; //找到最后一个分支
	while (curpos >= 0)
	{
		MaxAdjustDown(php->base, curpos, n);
		curpos--;
	}

	//排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&php->base[0], &php->base[end]);
		MaxAdjustDown(php->base, 0, end);
		end--;
	}
	//HeapPrint(php);
	int k = php->size - 1;
	for (int i = 0; i<n; ++i)
	{
		ar[i] = php->base[k--];
	}
}

#endif /* _HEAP_H_ */