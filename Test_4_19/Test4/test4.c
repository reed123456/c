#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int main()
{
	int *ptr2 = (int *)calloc(10, sizeof(int));//Ϊptr2���� 10*sizeof(int)�ֽڵĿռ�,����ʼ��Ϊ0
	assert(ptr2 != NULL);
	free(ptr2);
	ptr2 = NULL;//�ͷź��ÿ�

	int *ptr1 = (int *)malloc(sizeof(int)* 5);//Ϊptr1���� 5*sizeof(int)�ֽڵĿռ�
	assert(ptr1 != NULL);
	for (int i = 0; i < 5; i++)// 1 2 3 4 5
	{
		ptr1[i] = i + 1;
	}
	int *tmp = realloc(ptr1, sizeof(int)* 10);//��ptr1����Ϊ 5*sizeof(int)�ֽڵĿռ�
	if (NULL == tmp)//�ж�����ռ��Ƿ�ɹ�����ʧ��realloc()�����ͷ�ptr1,������ڴ�й©
	{
		free(ptr1);//�ͷ�ptr1
		return 0;
	}
	for (int i = 5; i < 10; i++)//...6 7 8 9 10
	{
		ptr1[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)//1 2 3 4 5 6 7 8 9 10
	{
		printf("%d ", ptr1[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}




/*
#include <stdio.h>

enum Day//����
{
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

int main()
{

	system("pause");
	return 0;
}


/*
//�������͵�����
union Un
{
	char c;
	int i;
};
*/


//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};//sz-->3
//void main()
//{
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//}

/*
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef struct Stu
{
	char name[10];//����
	int age;//����
	char sex[5];//�Ա�
	char id[20];//ѧ��
}Stu;


void printStu(Stu* pStu)//��ӡStu
{
	printf("%-8s%-5d%-5s%s\n", pStu->name, pStu->age, pStu->sex, pStu->id);
}
int main()
{
	Stu stu = { "alice", 18, "Ů", "6125012000" };//����ṹ���������ʼ��
	printStu(&stu);
	return 0;
}
*/
/*
#include <stdio.h>

//Ĭ�����:Ĭ�ϵĶ���ֵ8�ֽ�
//1��������������һ���� ��ֵ
//2�Զ�������Ҳ��һ������ֵ=�ڲ���Ա���͵����ֵ
//3�����ָ������ֵ: #pragma pack(n) n==2���ݴη�
//4�������Ч����ֵ:�����ָ������ֵ���������Ͷ���ֵ�Ľ�Сֵ8

#pragma pack (4)
typedef struct Test //8
{
	char a;//1+3
	double b;//8
	int C;//4
}Test; //sz-->16

void main()
{
	printf("Test size = %d\n",sizeof (Test));
	system("pause");
	return 0;
}
*/