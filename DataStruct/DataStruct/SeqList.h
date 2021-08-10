#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_

#include"Common.h"

#define ElemType int

//���ݽṹ�Ķ���
typedef struct SeqList
{
	ElemType *base;
	size_t    capacity;
	size_t    size;
}SeqList;

//��������
void SeqListInit(SeqList *pst, size_t capacity);
void SeqListPushBack(SeqList *pst, ElemType v);
void SeqListPushFront(SeqList *pst, ElemType v);
void SeqListPopBack(SeqList *pst);
void SeqListPopFront(SeqList *pst);
void SeqListInsertByPos(SeqList *pst, int pos, ElemType v);
size_t SeqListLength(SeqList *pst);
void SeqListDestroy(SeqList *pst);
void SeqListShow(SeqList *pst);

//����ʵ��
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
	//�������
	if(pst->size >= pst->capacity)
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	pst->base[pst->size++] = v;
}

void SeqListPushFront(SeqList *pst, ElemType v)
{
	//�������
	if(pst->size >= pst->capacity)
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	//�ƶ�����
	for(int i=pst->size; i>0; --i)
	{
		pst->base[i] = pst->base[i-1];
	}
	//��������
	pst->base[0] = v;
	pst->size++;
}

void SeqListPopBack(SeqList *pst)
{
	if(pst->size == 0)
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	//ɾ������
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	if(pst->size == 0)
	{
		printf("˳����ѿգ�����ɾ��.\n");
		return;
	}

	for(int i=0; i<pst->size-1; ++i)
		pst->base[i] = pst->base[i+1];
	pst->size--;
}

void SeqListInsertByPos(SeqList *pst, int pos, ElemType v)
{
	//�������
	if(pst->size >= pst->capacity)
	{
		printf("˳����������㣬%d ���ܲ���.\n", v);
		return;
	}

	//���λ��
	if(pos<0 || pos>pst->size)
	{
		printf("�����λ�÷Ƿ��� %d ���ܲ���.\n", v);
		return;
	}

	//��������
	for(int i=pst->size; i>pos; --i)
		pst->base[i] = pst->base[i-1];
	pst->base[pos] = v;
	pst->size++;
}

size_t SeqListLength(SeqList *pst)
{
	return pst->size;
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