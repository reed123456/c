#include <stdio.h>
#include <malloc.h>
#include <assert.h>

int main()
{
	int *ptr2 = (int *)calloc(10, sizeof(int));//为ptr2开辟 10*sizeof(int)字节的空间,并初始化为0
	assert(ptr2 != NULL);
	free(ptr2);
	ptr2 = NULL;//释放后置空

	int *ptr1 = (int *)malloc(sizeof(int)* 5);//为ptr1开辟 5*sizeof(int)字节的空间
	assert(ptr1 != NULL);
	for (int i = 0; i < 5; i++)// 1 2 3 4 5
	{
		ptr1[i] = i + 1;
	}
	int *tmp = realloc(ptr1, sizeof(int)* 10);//把ptr1调整为 5*sizeof(int)字节的空间
	if (NULL == tmp)//判断申请空间是否成功，若失败realloc()不会释放ptr1,会造成内存泄漏
	{
		free(ptr1);//释放ptr1
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

enum Day//星期
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
//联合类型的声明
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
	char name[10];//名字
	int age;//年龄
	char sex[5];//性别
	char id[20];//学号
}Stu;


void printStu(Stu* pStu)//打印Stu
{
	printf("%-8s%-5d%-5s%s\n", pStu->name, pStu->age, pStu->sex, pStu->id);
}
int main()
{
	Stu stu = { "alice", 18, "女", "6125012000" };//定义结构体变量并初始化
	printStu(&stu);
	return 0;
}
*/
/*
#include <stdio.h>

//默认情况:默认的对齐值8字节
//1基本数据类型有一个对 齐值
//2自定义类型也有一个对齐值=内部成员类型的最大值
//3程序的指定对齐值: #pragma pack(n) n==2的幂次方
//4程序的有效对齐值:程序的指定对齐值和数据类型对齐值的较小值8

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