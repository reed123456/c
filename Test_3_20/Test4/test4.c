#include <stdio.h>

int main()
{
	int i, j,  temp;
	int arr[3];
	printf("请输入三个数: ");
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("从大到小输出为：");
	for (i = 0; i < 3; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}