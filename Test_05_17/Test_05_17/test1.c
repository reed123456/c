#include <stdio.h>
#include <assert.h>

void BubbleSort(int* a, int n)
{
	assert(a);
	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				int tmp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = a[i - 1];
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

int main()
{
	int arr[] = { 1, 3, 4, 2, 12, 15, 9, 0, 34 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	BubbleSort(arr, sz);

	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}