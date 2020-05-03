#include <stdio.h>
#include <assert.h>

int removeElement(int* nums, int numsSize, int val){
	assert(nums);
	int loc = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[loc++] = nums[i];
		}
	}
	return loc;
}

int main()
{
	int arr[] = { 3, 2, 2, 3 };
	int key = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int len = removeElement(arr, sz, key);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}