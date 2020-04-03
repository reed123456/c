#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//结构体
typedef struct Stu
{
	char name[20];
	char id[18];
	short age;
	char sex[5];
}Stu;//全局变量

typedef struct I
{
	char buf[20];
	struct Stu s;
	int *p;
}T;

void print1(struct Stu tmp)
{
	printf("%s\t%s\t%d\t%s\n", tmp.name, tmp.id, tmp.age, tmp.sex);
}

void print2(struct Stu *tmp)
{
	printf("%s\t%s\t%d\t%s\n", tmp->name, tmp->id, tmp->age, tmp->sex);
}


int main()
{
	int a = 10;
	Stu s1 = {"Alice", "001", 18, "女"};//局部变量
	print1(s1);
	print2(&s1);//选2
	T st = { "bit", { "Alice", "001", 18, "女" }, &a, };
	T* pt = &st;
	printf("%s\n", st.buf);
	printf("%s\n", st.s.name);
	printf("%d\n", *(pt->p));
	system("pause");
	return 0;
}