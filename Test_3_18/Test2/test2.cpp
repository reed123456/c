#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

struct Book
{
	char name[30];
	double price;
	char id[30];
};
int main()
{
	struct Book b1 = { "ÉäµñÓ¢ÐÛ´«", 55.62, "INS-12321" };
	struct Book b2 = { "c++", 32.5, "INS-345652" };
	struct Book *ps = &b2;
	printf("name = %s\n", b1.name);
	printf("price = %lf\n", b1.price);
	printf("id = %s\n", b1.id);
	printf("name = %s\n", ps->name);
	printf("price = %lf\n", ps->price);
	printf("id = %s\n", ps->id);
	system("pause");
	return 0;
}