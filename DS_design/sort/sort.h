/*sort.h*/
#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>
#include <vld.h>
#include <malloc.h>

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//≤Â»Î≈≈–Ú
void InsertSort(int *elem, int first, int last);
void BinInsertSort(int *elem, int first, int last);
void ShellSort(int *elem, int first, int last);

//—°‘Ò≈≈–Ú
void SelectSort(int *elem, int first, int last);
void HeapSort(int *elem, int first, int last);

//Ωªªª≈≈–Ú
void BubbleSort(int *elem, int first, int last);
void QuickSort(int *elem, int first, int last);

//πÈ≤¢≈≈–Ú
void MergeSort(int *elem, int first, int last);

//////////////////////////////////////////////////////


//≤Â»Î≈≈–Ú--------------------------------------------------------------------------------------
//÷±Ω”≤Â»Î≈≈–Ú - “∆∂Ø∞Ê
void InsertSort(int *elem, int first, int last)
{
	for (int i = first + 1; i<last; ++i)
	{
		int end = i;
		int tmp = elem[end];
		while (end>first && tmp<elem[end - 1])
		{
			elem[end] = elem[end - 1];
			end--;
		}
		elem[end] = tmp;
	}
}

//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(int *elem, int first, int last)
{
	for (int i = first + 1; i<last; ++i)
	{
		int tmp = elem[i];
		int low = first;
		int high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (elem[mid] > tmp)
				high = mid - 1;
			if (elem[mid] <= tmp)
				low = mid + 1;
		}

		for (int j = i; j>low; --j)
			elem[j] = elem[j - 1];
		elem[low] = tmp;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int *elem, int first, int last)
{
	int dk = last - first;
	while (dk > 1)
	{
		dk = dk / 3 + 1;
		for (int i = first; i<last - dk; ++i)
		{
			if (elem[i + dk] < elem[i])
			{
				int end = i;
				int tmp = elem[end + dk];
				while (end >= first && tmp<elem[end])
				{
					elem[end + dk] = elem[end];
					end -= dk;
				}
				elem[end + dk] = tmp;
			}
		}
	}
}

//—°‘Ò≈≈–Ú--------------------------------------------------------------------------------------
//÷±Ω”—°‘Ò≈≈–Ú
int GetMinIndex(int *elem, int first, int last)
{
	int min_val = elem[first];
	int index = first;
	for (int i = first + 1; i<last; ++i)
	{
		if (elem[i] < min_val)
		{
			min_val = elem[i];
			index = i;
		}
	}
	return index;
}
void SelectSort(int *elem, int first, int last)
{
	for (int i = first; i<last - 1; ++i)
	{
		int index = GetMinIndex(elem, i, last);
		if (index != i)
			Swap(&elem[index], &elem[i]);
	}
}
//∂—≈≈–Ú
void _AdjustDown(int *elem, int first, int last, int start)
{
	int n = last - first;
	int i = start;
	int j = 2 * i + 1;

	int tmp = elem[i];
	while (j < n)
	{
		if (j + 1<n && elem[j] < elem[j + 1])
			j++;
		if (tmp < elem[j])
		{
			elem[i] = elem[j];
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
	elem[i] = tmp;

}
void HeapSort(int *elem, int first, int last)
{
	//µ˜’˚≥…¥Û∂—
	int n = last - first;
	int curpos = n / 2 - 1;
	while (curpos >= 0)
	{
		_AdjustDown(elem, first, last, curpos);
		curpos--;
	}

	//≈≈–Ú
	int end = last - 1;
	while (end > first)
	{
		Swap(&elem[end], &elem[first]);
		end--;
		_AdjustDown(elem, first, end + 1, first);
	}
}

//Ωªªª≈≈–Ú----------------------------------------------------------------------------------------
//√∞≈›≈≈–Ú
void BubbleSort(int *elem, int first, int last)
{
	bool is_swap = false;
	for (int i = first; i<last - 1; ++i)
	{
		for (int j = first; j<last - i - 1; ++j)
		{
			if (elem[j] > elem[j + 1])
			{
				Swap(&elem[j], &elem[j + 1]);
				is_swap = true;
			}
		}

		if (!is_swap)
			break;
		else
			is_swap = false;
	}
}

//øÏÀŸ≈≈–Ú
int _Partition(int *elem, int first, int last)
{
	int key = elem[first];
	while (first < last)
	{
		while (first<last && elem[last] >= key)
			last--;
		elem[first] = elem[last];

		while (first<last && elem[first]<key)
			first++;
		elem[last] = elem[first];
	}
	elem[first] = key;
	return first;
}
void QuickSort(int *elem, int first, int last)
{
	if (first >= last - 1)
		return;

	int pos = _Partition(elem, first, last - 1);

	QuickSort(elem, first, pos);   //[   )
	QuickSort(elem, pos + 1, last);
}

//πÈ≤¢≈≈–Ú-----------------------------------------------------------------------------------------
void _MergeSort(int *elem, int first, int last, int *tmp)
{
	if (first >= last)
		return;
	int mid = (first + last) / 2;
	_MergeSort(elem, first, mid, tmp);
	_MergeSort(elem, mid + 1, last, tmp);

	//πÈ≤¢
	int begin1, end1, begin2, end2;
	begin1 = first, end1 = mid;
	begin2 = mid + 1, end2 = last;

	int i = first;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (elem[begin1] < elem[begin2])
			tmp[i++] = elem[begin1++];
		else
			tmp[i++] = elem[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[i++] = elem[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = elem[begin2++];
	}

	memcpy(elem + first, tmp + first, sizeof(int)*(last - first + 1));
}
void MergeSort(int *elem, int first, int last)
{
	int n = last - first;
	int *tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(elem, first, last - 1, tmp);
	free(tmp);
}

#endif /* _SORT_H_ */