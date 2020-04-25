#include <stdio.h>
#include <string.h>
#include <assert.h>
void Resvrve(char *str, int start, int end)
{
	assert(str);
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
void ReverseWord(char *str)
{
	assert(str);
	int len = strlen(str);
	if (len == 1)
		return;
	int start = 0;
	int end = len - 1;
	Resvrve(str, start, end);
	for (int i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			end = i - 1;
			Resvrve(str, start, end);
			i++;
			start = i;
		}
		
	}

}
int main()
{
	char str[100] = { 0 };
	gets(str);
	ReverseWord(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}