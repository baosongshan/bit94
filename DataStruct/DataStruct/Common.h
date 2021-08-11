#ifndef _COMMON_H_
#define _COMMON_H_

//预防头文件的重复引入
//#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<vld.h>  //内存泄漏的检测工具

#define ElemType int
void Swap(ElemType *a, ElemType *b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif /* _COMMON_H_ */