//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词 :
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int crimnal[4] = { 0 };
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		crimnal[i] = 1;
		
		if ((crimnal[0] == 0) +
			(crimnal[2] == 1) +
			(crimnal[3] == 1) +
			(crimnal[3] == 0) == 3)
		{
			printf("凶手是%c\n", i + 'A');
			break;
		}
		crimnal[i] = 0;
	}
	
	system("pause");
	return 0;
}

//int main()
//{
//	int murder[4] = { 0 }; //默认4个人都不是凶手
//
//	int i;
//	for (i = 0; i < 4; i++) //遍历假设四个人中的某个人是凶手
//	{
//		murder[i] = 1; //假设某个人是凶手
//	
//		if ((murder[0] != 1) +
//			(murder[2] == 1) +
//			(murder[3] == 1) +
//			(murder[3] != 1) == 3)
//		{
//			break; //满足就代表就是你了！
//		}
//		murder[i] = 0; //不满足还他清白
//	}
//
//	putchar('A' + i); //打印凶手的编号。我们的编号是0 1 2 3，加上'A'后变成A B C D。
//	system("pause");
//	return 0;
//}