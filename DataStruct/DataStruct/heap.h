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

//С��
void MinHeapInsert(Heap *php, HeapDataType x);
HeapDataType MinHeapRemove(Heap *php);
void MinAdjustUp(HeapDataType *base, int start);
void MinAdjustDown(HeapDataType *base, int start, int n);
void MinHeapSort(Heap *php);

//���
void MaxHeapInsert(Heap *php, HeapDataType x);
HeapDataType MaxHeapRemove(Heap *php);
void MaxAdjustUp(HeapDataType *base, int start);
void MaxAdjustDown(HeapDataType *base, int start, int n);
void MaxHeapSort(Heap *php, int ar[], int n);


//��ʼ��
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

//����Ԫ��
void MinHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;

		//����ΪС�ѽṹ  �������ϵ���
		MinAdjustUp(php->base, php->size);
		php->size++;
	}
}

//С�ѵ���
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

//���ϲ���
void MinAdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapDataType tmp = base[j];

	while (j > 0)
	{
		if (tmp < base[i])
		{
			base[j] = base[i]; //����
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	base[j] = tmp;
}



//���²���
void MinAdjustDown(HeapDataType *base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && base[j]>base[j + 1]) //�ҳ�����������С��ֵ
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

//������
void MinHeapSort(Heap *php, int ar[], int n)
{
	for (int i = 0; i<n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//������С��
	int curpos = n / 2 - 1; //�ҵ����һ����֧
	while (curpos >= 0)
	{
		MinAdjustDown(php->base, curpos, n);
		curpos--;
	}

	//����
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
//���
//����Ԫ��
void MaxHeapInsert(Heap *php, HeapDataType x)
{
	assert(php != NULL);
	if (php->size < php->capacity)
	{
		php->base[php->size] = x;

		//����ΪС�ѽṹ  �������ϵ���
		MaxAdjustUp(php->base, php->size);
		php->size++;
	}
}

//С�ѵ���
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

//���ϲ���
void MaxAdjustUp(HeapDataType *base, int start)
{
	int j = start;
	int i = (j - 1) / 2;

	HeapDataType tmp = base[j];

	while (j > 0)
	{
		if (tmp > base[i])
		{
			base[j] = base[i]; //����
			j = i;
			i = (j - 1) / 2;
		}
		else
			break;
	}
	base[j] = tmp;
}



//���²���
void MaxAdjustDown(HeapDataType *base, int start, int n)
{
	int i = start;
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j + 1<n && base[j]<base[j + 1]) //�ҳ�����������С��ֵ
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

//������
void MaxHeapSort(Heap *php, int ar[], int n)
{
	for (int i = 0; i<n; ++i)
		php->base[i] = ar[i];
	php->size = n;

	//������С��
	int curpos = n / 2 - 1; //�ҵ����һ����֧
	while (curpos >= 0)
	{
		MaxAdjustDown(php->base, curpos, n);
		curpos--;
	}

	//����
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