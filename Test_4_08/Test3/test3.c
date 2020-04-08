#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int check(int* score, int sz)
{
	int tmp[5] = { 0 };
	int i;
	int j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (score[i] == j + 1)
			{
				tmp[j] += 1;
			}
		}
		if (tmp[0] == 1 && tmp[1] == 1 && tmp[2] == 1 && tmp[3] == 1 && tmp[4] == 1)
			return 1;
	}
	return 0;
}

int main()
{
	int score[5] = { 0 }; 
	int sz = sizeof(score) / sizeof(score[0]);
	for (score[0] = 1; score[0] <= sz; score[0]++)
	{
		for (score[1] = 1; score[1] <= sz; score[1]++)
		{
			for (score[2] = 1; score[2] <= sz; score[2]++)
			{
				for (score[3] = 1; score[3] <= sz; score[3]++)
				{
					for (score[4] = 1; score[4] <= sz; score[4]++) //五层循环遍历
					{
						if ((score[1] == 2) + (score[0] == 3) == 1 && //B第二，我第三
							(score[1] == 2) + (score[4] == 4) == 1 && //我第二，E第四
							(score[2] == 1) + (score[3] == 2) == 1 && //我第一，D第二
							(score[2] == 5) + (score[3] == 3) == 1 && //C最后，我第三
							(score[4] == 4) + (score[0] == 1) == 1 && //我第四，A第一
							check(score, sz) == 1)
		
						{
							//printf("%d\n", check(score, sz));
							for (int i = 0; i < sz; i++)
							{
								printf("%d ", score[i]);
							}
							printf("\n");
						}
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}