#define _CRT_SECURE_NO_WARNINGS 1

#define SwapIntBit(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)

int main()
{
	int a = 100;
	printf("%d\n", SwapIntBit(a));
	system("pause");
	return 0;
}