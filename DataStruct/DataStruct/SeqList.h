#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

#include"Common.h"

#define INC_SIZE 3

//数据结构的定义
typedef struct SeqList
{
	ElemType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

//函数声明
bool _Inc(SeqList *pst);
bool _IsFull(SeqList *pst);
bool _IsEmpty(SeqList *pst);
//--------------------------------------------------
void SeqListInit(SeqList *pst, size_t capacity);
void SeqListPushBack(SeqList *pst, ElemType v);
void SeqListPushFront(SeqList *pst, ElemType v);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);
void SeqListEraseByPos(SeqList *pst, int pos);
void SeqListEraseByVal(SeqList *pst, ElemType key);
void SeqListInsertByPos(SeqList *pst, int pos, ElemType v);
void SeqListInsertByVal(SeqList *pst, ElemType v);
size_t SeqListCapacity(SeqList *pst);
size_t SeqListLength(SeqList *pst);

ElemType SeqListFindByPos(SeqList *pst, int pos);
int SeqListFindByVal(SeqList *pst, ElemType key);

void SeqListSort(SeqList *pst);
void SeqListReverse(SeqList *pst);

void SeqListClear(SeqList *pst);
void SeqListDestroy(SeqList *pst);
void SeqListShow(SeqList *pst);

//函数实现
bool _Inc(SeqList *pst)
{
	pst->base = (ElemType *)realloc(pst->base, sizeof(ElemType) * (pst->capacity+INC_SIZE));
	if(pst->base == NULL)
		return false;
	pst->capacity += INC_SIZE;
	return true;
}
bool _IsFull(SeqList *pst)
{return pst->size >= pst->capacity;}
bool _IsEmpty(SeqList *pst)
{return pst->size == 0;}

void SeqListInit(SeqList *pst, size_t capacity)
{
	pst->capacity = capacity;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*pst->capacity);
	pst->size = 0;
}

void SeqListPushBack(SeqList *pst, ElemType v)
{
	//检查容量
	if(_IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	pst->base[pst->size++] = v;
}

void SeqListPushFront(SeqList *pst, ElemType v)
{
	//检查容量
	if(_IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	//移动数据
	for(int i=pst->size; i>0; --i)
	{
		pst->base[i] = pst->base[i-1];
	}
	//插入数据
	pst->base[0] = v;
	pst->size++;
}

void SeqListPopBack(SeqList *pst)
{
	if(_IsEmpty(pst))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}

	//删除数据
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	if(_IsEmpty(pst))
	{
		printf("顺序表已空，不能删除.\n");
		return;
	}

	for(int i=0; i<pst->size-1; ++i)
		pst->base[i] = pst->base[i+1];
	pst->size--;
}

void SeqListInsertByPos(SeqList *pst, int pos, ElemType v)
{
	//检查容量
	if(_IsFull(pst) && !_Inc(pst))
	{
		printf("顺序表容量不足，%d 不能插入.\n", v);
		return;
	}

	//检查位置
	if(pos<0 || pos>pst->size)
	{
		printf("插入的位置非法， %d 不能插入.\n", v);
		return;
	}

	//插入数据
	for(int i=pst->size; i>pos; --i)
		pst->base[i] = pst->base[i-1];
	pst->base[pos] = v;
	pst->size++;
}

void SeqListInsertByVal(SeqList *pst, ElemType v)
{
	//寻找插入的位置
	int pos = 0;
	while(pos<pst->size &&  v>pst->base[pos])
		pos++;

	//插入数据
	SeqListInsertByPos(pst, pos, v);
}

void SeqListEraseByPos(SeqList *pst, int pos)
{
	//检查位置
	if(pos<0 || pos>=pst->size)
	{
		printf("删除的位置非法，不能删除数据.\n");
		return;
	}

	//删除数据
	for(int i=pos; i<pst->size-1; ++i)
		pst->base[i] = pst->base[i+1];
	pst->size--;
}

void SeqListEraseByVal(SeqList *pst, ElemType key)
{
	//查找关键值
	int pos = SeqListFindByVal(pst, key);
	if(pos == -1)
	{
		printf("要删除的数据不存在.\n");
		return;
	}

	//删除数据
	SeqListEraseByPos(pst, pos);
}

ElemType SeqListFindByPos(SeqList *pst, int pos)
{
	//检查位置
	assert(pos>=0 && pos<pst->size);
	return pst->base[pos];
}

int SeqListFindByVal(SeqList *pst, ElemType key)
{
	for(int i=0; i<pst->size; ++i)
	{
		if(key == pst->base[i])
			return i;
	}
	return -1;
}

size_t SeqListLength(SeqList *pst)
{
	return pst->size;
}
size_t SeqListCapacity(SeqList *pst)
{
	return pst->capacity;
}

void SeqListClear(SeqList *pst)
{
	pst->size = 0;
}

void SeqListSort(SeqList *pst)
{
	for(int i=0; i<pst->size-1; ++i)
	{
		bool is_swap = false;

		for(int j=0; j<pst->size-i-1; ++j)
		{
			if(pst->base[j] > pst->base[j+1])
			{
				Swap(&(pst->base[j]), &(pst->base[j+1]));
				is_swap = true;
			}
		}

		if(!is_swap)  //没有交换过数据
			break;
	}
}

void SeqListReverse(SeqList *pst)
{
	int left = 0;
	int right = pst->size-1;

	while(left < right)
	{
		Swap(&(pst->base[left]), &(pst->base[right]));
		left++;
		right--;
	}
}

void SeqListDestroy(SeqList *pst)
{
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

void SeqListShow(SeqList *pst)
{
	for(int i=0; i<pst->size; ++i)
		printf("%d ", pst->base[i]);
	printf("\n");
}

#endif /* _SEQ_LIST_H_ */

/*
void SeqListEraseByVal(SeqList *pst, ElemType key)
{
	//查找关键值
	int pos;
	for(pos=0; pos<pst->size; ++pos)
	{
		if(key == pst->base[pos])
			break;
	}
	if(pos >= pst->size)
	{
		printf("要删除的数据不存在.\n");
		return;
	}

	//删除数据
	for(int i=pos; i<pst->size-1; ++i)
		pst->base[i] = pst->base[i+1];
	pst->size--;
}
*/