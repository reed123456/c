#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int * max = NULL;
	int arr[10];
	printf("ÇëÊäÈë10¸öÊı×Ö£º\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (max == NULL)
		{
			max = &arr[i];
		}
		else if (*max < arr[i])
		{
			max = &arr[i];
		}
	}
	printf("max = %d\n", *max);

	system("pause");
	return 0;
}