#include <stdio.h>

int main()
{
	char c[20];
	FILE *fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return -1;
	}
	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
	while ((fgets(c,20,fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
	{
		puts(c);
	}
	//�ж���ʲôԭ�������
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	/*
	if (fp == NULL)
	{
		printf("���ļ�ʧ��...\n");
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		fprintf(fp, "%d ", i + 1);
	}
	*/
	fclose(fp);
	system("pause");
	return 0;
}