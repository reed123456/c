#ifndef _COMMON_H_
#define _COMMOM_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

#define ElemType char

void Swap(ElemType *a, ElemType *b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

#endif /*_COMMOM_H_*/