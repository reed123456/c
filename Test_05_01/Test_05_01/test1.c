#include <stdio.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int sum, len_K, len;
	int * res;
	if (K == 0)
	{
		*returnSize = ASize;
		return A;
	}
	len_K = log10(K) + 1;
	*returnSize = (ASize > len_K) ? ASize + 1 : len_K + 1;
	res = (int *)malloc(*returnSize * sizeof(int));
	len = *returnSize;
	while (len - 1 >= 1 || K > 0)
	{
		if (ASize > 0)
			K += A[--ASize];
		res[--len] = K % 10;
		K /= 10;
	}
	*returnSize -= len;
	return res + len;

}

int main()
{
	int arr[] = { 1, 2, 0, 0 };
	int k = 34;
	int arrsz;
	int sz = sizeof(arr) / sizeof(arr[0]);
	addToArrayForm(arr, sz, k, &arrsz);

	for (int i = 0; i < arrsz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}