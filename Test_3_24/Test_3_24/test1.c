#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[20] = "#######";
	char arr2[] = "bit";
	strcpy(arr1, arr2);//bit\0########
	printf("%s\n", arr1);
	char arr3[] = "hello bit";
	memset(arr3, '*', 5);
	printf("%s\n", arr3);
	system("pause");
	return 0;
}