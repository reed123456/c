#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int day;
	printf("���������֣�");
	scanf("%d", &day);
	switch (day){
	case 1: printf("����������һ��\n"); break;
	case 2: printf("���������ڶ���\n"); break;
	case 3: printf("��������������\n"); break;
	case 4: printf("�����������ġ�\n"); break;
	case 5: printf("�����������塣\n"); break;
	case 6: printf("��������������\n"); break;
	case 7: printf("�����������졣\n"); break;
	default:printf("�����ڵ�����Ŷ��\n");
	}
	system("pause");
	return 0;
}