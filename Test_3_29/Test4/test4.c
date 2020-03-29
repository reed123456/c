#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

struct stu
{
	char name[20];
	int age;
	int tele[12];
	char sex[15];
};
int main()
{
	int a = 10;
	int b = 20;
	//int max = (a>b)? (a):(b);
	//printf("max = %d\n", max);
	struct stu s = {"alice", 18, "15686381331", "Ů"};
	struct stu * ps = &s;
	//strcpy(s.name, "alice");
	printf("%s\n", s.name);
	printf("%d\n", ps->age);
	system("pause");
	return 0;
}