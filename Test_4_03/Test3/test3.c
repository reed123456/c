#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�ṹ��
typedef struct Stu
{
	char name[20];
	char id[18];
	short age;
	char sex[5];
}Stu;//ȫ�ֱ���

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
	Stu s1 = {"Alice", "001", 18, "Ů"};//�ֲ�����
	print1(s1);
	print2(&s1);//ѡ2
	T st = { "bit", { "Alice", "001", 18, "Ů" }, &a, };
	T* pt = &st;
	printf("%s\n", st.buf);
	printf("%s\n", st.s.name);
	printf("%d\n", *(pt->p));
	system("pause");
	return 0;
}