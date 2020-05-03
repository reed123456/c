#include <stdio.h>
#include <string.h>

void rotate(int* nums, int numsSize, int k){
	if (k == 0)
		return;
	k = k % numsSize;
	int * arr1 = (int *)malloc(sizeof(int)*numsSize * 2);
	for (int i = 0; i < numsSize * 2; i++)
		arr1[i] = nums[i % numsSize];
	for (int i = 0; i < numsSize; i++)
	 	nums[i] = arr1[i + numsSize - k];
	free(arr1);
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 1;
	rotate(arr, sz, k);
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}