#include <stdio.h>
#include <assert.h>
int removeDuplicates(int* nums, int numsSize){
	assert(nums);
	if (numsSize < 2)
		return numsSize;
	int loc = 1;
	for (int i = 1; i < numsSize; i++)
	{
		if (nums[i] != nums[i-1])
		{
			nums[loc++] = nums[i];
		}
	}
	return loc;
}

int main()
{
	int arr[] = { 1, 1, 2 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int len = removeDuplicates(arr, sz);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}