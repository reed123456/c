#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//��ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĸߵ�ַ�У������ݵĸ�λ���������ڴ�ĵ͵�ַ�У�
//С�ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĵ͵�ַ�У������ݵĸ�λ, ���������ڴ�ĸߵ�ַ��
bool CheckModel()
{
	int i = 1;
	return (*(char *)&i) == 1;
}

int main()
{
	int flag = CheckModel();
	if (flag)
	{
		printf("С�˴洢ģʽ\n");
	}
	else
	{
		printf("��˴洢ģʽ\n");
	}
	system("pause");
	return 0;
}