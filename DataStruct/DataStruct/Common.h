#ifndef _COMMON_H_
#define _COMMON_H_

//Ԥ��ͷ�ļ����ظ�����
//#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<vld.h>  //�ڴ�й©�ļ�⹤��

#define ElemType int
void Swap(ElemType *a, ElemType *b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /* _COMMON_H_ */