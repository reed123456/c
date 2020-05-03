#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	for (int i = 0; i < n; i++)
		nums1[i+m] = nums2[i];

	for (int i = 0; i < m + n - 1; i++)
	{
		for (int j = 0; j < m + n - i - 1; j++)
		{
			if (nums1[j] > nums1[j+1])
			{
				int tmp = nums1[j];
				nums1[j] = nums1[j+1];
				nums1[j+1] = tmp;
			}
		}
	}
}

int main()
{
	int nums1[] = { 2,0 };
	int nums2[] = { 1};
	int sz1 = sizeof(nums1) / sizeof(nums1[0]);
	int m = 1;
	int sz2 = sizeof(nums2) / sizeof(nums2[0]);
	int n = 1;
	merge(nums1, sz1, m, nums2, sz2, n);
	for (int i = 0; i < m + n; i++)
		printf("%d ", nums1[i]);
	printf("\n");
	system("pause");
	return 0;
}