//#include <stdio.h>
//#include <assert.h>
//
////void *my_memmove(void *dest, const void *src, size_t count)
////{
////	assert(src != NULL);
////	assert(dest != NULL);
////	char* pdest = (char *)dest;
////	char* psrc = (char *)src;
////	if (pdest >= psrc + count || psrc > pdest)
////	{
////		while (count-- != 0)
////		{
////			*pdest++ = *psrc++;
////		}
////	}
////	else
////	{
////		pdest = pdest + count - 1;
////		psrc = pdest + count - 1;
////		while (count-- != 0)
////		{
////			*pdest-- = *psrc--;
////		}
////	}
////	return dest;
////}
//
//int mian()
//{
//	//char str[] = "cdefgh";
//	//char *str1 = "ab";
//	////my_memmove(str, str1, 2);
//	//printf("%s\n", str);
//	printf("hhhhh\n");
//	//system("pause");
//	return 0;
//}