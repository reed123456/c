#ifndef _COMMON_H_
#define _COMMOM_H_

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define ElemType int

void Swap(ElemType *a, ElemType *b)
{
	ElemType temp = *a;
	*a = *b;
	*b = temp;
}

#endif /*_COMMOM_H_*/