#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int i ;
	for (i = 1; i <= 100; i++){
		if (i % 2 == 0){
			printf("%d: ż��\n", i);
		}
		else{
			printf("%d: ����\n", i);
		}
	}
	
	system("pause");
	return 0;
}