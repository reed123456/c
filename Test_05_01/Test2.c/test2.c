#include <stdio.h>
#include <string.h>
#include <vld.h>
void rotate(int* nums, int numsSize, int k){
	if (k == 0)
		return;
	k = k % numsSize;
	int *num = (int *)malloc(sizeof(int)*numsSize * 2);
	memcpy(num, nums, numsSize);
	memcpy(num + numsSize, nums, numsSize);
	memcpy(nums, num + k, numsSize);
	free(num);
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);
	rotate(arr, sz, k);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}