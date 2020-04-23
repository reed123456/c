//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	printf("line = %s\n", __LINE__);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	printf("file = %s\n", __FILE__);//__FILE__   进行编译的源文件
//	printf("line = %s\n", __LINE__);//__LINE__   文件当前的行号
//	printf("line = %s\n", __DATE__);//__DATE__   文件被编译的日期
//	printf("line = %s\n", __TIME__);//__TIME__   文件被编译的时间
//	system("pause");
//	return 0;
//}

/*
int main(void)
{
	double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	double b = 0.0;
	size_t ret_code = 0;
	FILE *fp = fopen("test.bin", "wb"); // 必须用二进制模式
	fwrite(a, sizeof(*a), 5, fp); // 写 double 的数组
	fclose(fp);
	fp = fopen("test.bin", "rb");
	// 读 double 的数组
	while ((ret_code = fread(&b, sizeof(double), 1, fp)) >= 1)
	{
		printf("%lf\n", b);
	}
	if (feof(fp))
		printf("Error reading test.bin: unexpected end of file\n");
	else if (ferror(fp)) {
		perror("Error reading test.bin");
	}
	fclose(fp);
	fp = NULL;
}
//int main()
//{
//	FILE* fp = fopen("C:\\Users\\wpy94\\Desktop\\test.txt", "w");
//	for (int i = 0; i < 10; i++)
//		fprintf(fp, "%d ", i + 1);
//	fclose(fp);
//	system("pause");
//	return 0;
//}


int fseek(FILE * stream, long int offset, int origin);
int main()
{
	FILE * pFile = fopen("example.txt", "wb");
	fseek(pFile, 9, SEEK_SET);//SEEK_CUR Current position of file pointer
                              //SEEK_END End of file
                              //SEEK_SET Beginning of file
	return 0;
}

int main(void)
{
	int c; // 注意：int，非char，要求处理EOF
	FILE* fp = fopen("test.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return -1;
	}
	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
	{
		putchar(c);
	}
	//判断是什么原因结束的
	if (ferror(fp))
		puts("I/O error when reading");
	else if (feof(fp))
		puts("End of file reached successfully");
	fclose(fp);
}
*/