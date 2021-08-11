#ifndef _LIST_H_
#define _LIST_H_

#include"Common.h"

//定义节点类型
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

void InitList(List *plist)
{
	*plist = NULL;
}

//1->2->3->4->5->....->10
void CreateList(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	ListNode *p = *plist;  //尾插法
	for(int i=2; i<=10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		//链接节点
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

#endif /* _LIST_H_ */