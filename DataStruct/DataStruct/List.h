#ifndef _LIST_H_
#define _LIST_H_

#include"Common.h"

typedef struct ListNode
{
	ElemType data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//����������
ListNode* _Buynode(ElemType v);
void ListInit(List *plist);
void ListShow(List plist);
void ListPushBack(List *plist, ElemType v);
void ListPushFront(List *plist, ElemType v);
void ListPopBack(List *plist);
void ListPopFront(List *plist);

void ListErase(List *plist, ElemType key);
void ListClear(List *plist);
void ListDestroy(List *plist);

ListNode* ListFind(List plist, ElemType key);
size_t ListLength(List plist);

//������ʵ��

ListNode* _Buynode(ElemType v)
{
	ListNode *s = (ListNode*)malloc(sizeof(ListNode));
	assert(s != NULL);
	s->data = v;
	s->next = NULL;

	return s;
}

void ListInit(List *plist)
{
	*plist = NULL;
}

void ListPushBack(List *plist, ElemType v)
{
	//����ڵ�
	ListNode *s = _Buynode(v);

	//����ڵ�
	ListNode *p = *plist;
	if(p == NULL)
	{
		*plist = s;
		return;
	}

	while(p->next != NULL)
		p = p->next;

	p->next = s;
}

void ListPushFront(List *plist, ElemType v)
{
	ListNode *s = _Buynode(v);
	s->next = *plist;
	*plist = s;
}

void ListPopBack(List *plist)
{
	ListNode *p = *plist;
	ListNode *prev = NULL;

	if(*plist == NULL)
		return;
	
	while(p->next != NULL)
	{
		prev = p;
		p = p->next;
	}

	if(prev == NULL)
		*plist = NULL;
	else
		prev->next = NULL;
	free(p);
}

void ListPopFront(List *plist)
{
	ListNode *p = *plist;
	if(*plist == NULL)
		return;

	*plist = p->next;
	free(p);
}

void ListShow(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

size_t ListLength(List plist)
{
	ListNode *p = plist;
	size_t len = 0;
	while(p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

ListNode* ListFind(List plist, ElemType key)
{
	ListNode *p = plist;
	while(p!=NULL && p->data!=key)
		p = p->next;
	return p;

	/*
	ListNode *p = plist;
	while(p != NULL)
	{
		if(p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
	*/
}

void ListErase(List *plist, ElemType key)
{
	ListNode *p = *plist;
	ListNode *prev = NULL;
	if(p == NULL)
		return;

	while(p!=NULL && p->data!=key)
	{
		prev = p;
		p = p->next;
	}
	if(p == NULL)
		return;

	if(prev == NULL)
		*plist = p->next;
	else
		prev->next = p->next;
	free(p);
}

void ListClear(List *plist)
{
	ListNode *p = NULL;
	while(*plist != NULL)
	{
		p = *plist;
		*plist = p->next;
		free(p);
	}
}

void ListDestroy(List *plist)
{
	ListClear(plist);
}



/////////////////////////////////////////////////////////////////////

/*
//����ڵ�����
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//����ͷ���
void InitList(List *plist)
{
	*plist = NULL;
}

void CreateList_Tail(List *plist)
{
	ListNode *p = *plist;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		if(p == NULL)
			*plist = s;
		else
			p->next = s;
		p = s;
	}
}
void ShowList(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

/*
//��ͷ���
void InitList(List *plist)
{
	//����ͷ���
	*plist = (ListNode*)malloc(sizeof(ListNode));
	(*plist)->next = NULL;
}

void CreateList_Tail(List *plist)
{
	ListNode *p = *plist;
	for(int i=1; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
void ShowList(List plist)
{
	ListNode *p = plist->next;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

/*
//����ͷ���
void InitList(List *plist)
{
	*plist = NULL;
}


//1->2->3->4->5->....->10
void CreateList_Tail(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	ListNode *p = *plist;  //β�巨
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//���ӽڵ�
		p->next = s;
		p = s;
	}
}

void CreateList_Front(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	//ͷ�巨
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = *plist;
		*plist = s;
	}
}

void ShowList(List plist)
{
	ListNode *p = plist;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/
#endif /* _LIST_H_ */