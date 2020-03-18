#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct stu
{
	char name[50];
	char sex[20];
	int age;
};

void print(struct stu *p)
{
	printf("name = %s sex = %s age = %d\n", p->name, p->sex, p->age);
}

int main()
{
	struct stu stu1 = { "Alice", "Å®", 16 };
	struct stu stu2 = { "Ð¡Âú", "Å®", 18 };
	print(&stu1);
	print(&stu2);
	stu1.age = 19;
	strcpy(stu1.name, "Ççö©");
	print(&stu1);
	system("pause");
	return 0;
}