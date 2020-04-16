#include <stdio.h>
#include <assert.h>

void *my_memcpy(void *dest, const void *src, size_t count)
{
	assert(src != NULL);
	assert(dest != NULL);
	char* pdest = (char *)dest;
	char* psrc = (char *)src;
	if (pdest >= psrc + count || psrc > pdest)
	{
		while (count-- != 0)
		{
			*pdest++ = *psrc++;
		}
	}
	else
	{
		pdest = pdest + count - 1;
		psrc = psrc + count - 1;
		while (count-- != 0)
		{
			*pdest-- = *psrc--;
		}
	}
	return dest;
}

int main()
{
	char str[] = "cdefgh";
	char str1[] = "ab";
	my_memcpy(str+1, str, 3);
	printf("%s\n", str);
	system("pause");
	return 0;
}