//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ��� :
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
////��֪3����˵���滰��1����˵���Ǽٻ���
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
			printf("������%c\n", i + 'A');
			break;
		}
		crimnal[i] = 0;
	}
	
	system("pause");
	return 0;
}

//int main()
//{
//	int murder[4] = { 0 }; //Ĭ��4���˶���������
//
//	int i;
//	for (i = 0; i < 4; i++) //���������ĸ����е�ĳ����������
//	{
//		murder[i] = 1; //����ĳ����������
//	
//		if ((murder[0] != 1) +
//			(murder[2] == 1) +
//			(murder[3] == 1) +
//			(murder[3] != 1) == 3)
//		{
//			break; //����ʹ���������ˣ�
//		}
//		murder[i] = 0; //�����㻹�����
//	}
//
//	putchar('A' + i); //��ӡ���ֵı�š����ǵı����0 1 2 3������'A'����A B C D��
//	system("pause");
//	return 0;
//}