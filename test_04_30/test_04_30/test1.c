#include <stdio.h>

int main()
{
	char c[20];
	FILE *fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return -1;
	}
	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	while ((fgets(c,20,fp)) != EOF) // 标准C I/O读取文件循环
	{
		puts(c);
	}
	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	/*
	if (fp == NULL)
	{
		printf("打开文件失败...\n");
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