#include"SeqList.h"
#include"List.h"

void main()
{
	List mylist;//  ListNode *mylist;
	InitList(&mylist);
	CreateList(&mylist);
	ShowList(mylist);
}

/*
int main(int argc, char *argv[])
{
	SeqList mylist;
	SeqListInit(&mylist, 8);

	ElemType item, value, key;
	int pos;
	int select = 1;
	while(select)
	{
		printf("********************************************\n");
		printf("* [1] push_back           [2] push_front   *\n");
		printf("* [3] show_list           [0] quit_system  *\n");
		printf("* [4] pop_back            [5] pop_front    *\n");
		printf("* [6] insert_pos          [7] insert_val   *\n");
		printf("* [8] erase_pos           [9] erase_val    *\n");
		printf("* [10] find_pos           [11] find_val    *\n");
		printf("* [12] sort               [13] reverse     *\n");
		printf("* [14] length             [15] capacity    *\n");
		printf("* [16] clear              [*17] destroy    *\n");
		printf("********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;

		switch(select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:>");
			while(scanf("%d", &item), item!=-1)
			{
				SeqListPushFront(&mylist, item);
			}
			break;
		case 3:
			SeqListShow(&mylist);
			break;
		case 4:
			SeqListPopBack(&mylist);
			break;
		case 5:
			SeqListPopFront(&mylist);
			break;
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsertByPos(&mylist, pos, item);
			break;
		case 7:
			printf("请输入要插入的值:>");
			scanf("%d", &item);
			SeqListInsertByVal(&mylist, item);
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqListEraseByPos(&mylist, pos);
			break;
		case 9:
			printf("请输入要删除的值:>");
			scanf("%d", &key);
			SeqListEraseByVal(&mylist, key);
			break;
		case 10:
			printf("请输入要查找的位置:>");
			scanf("%d", &pos);
			value = SeqListFindByPos(&mylist, pos);
			printf("在%d位置的值为:> %d\n", pos, value);
			break;
		case 11:
			printf("请输入要查找的值:>");
			scanf("%d", &key);
			pos = SeqListFindByVal(&mylist, key);
			if(pos == -1)
				printf("要查找的%d数据不存在.\n", key);
			else
				printf("要查找的数据%d在 %d位置.\n", key, pos);
			break;
		case 12:
			SeqListSort(&mylist);
			break;
		case 13:
			SeqListReverse(&mylist);
			break;
		case 14:
			printf("顺序表的长度为:> %d\n", SeqListLength(&mylist));
			break;
		case 15:
			printf("顺序表的容量为:> %d\n", SeqListCapacity(&mylist));
			break;
		case 16:
			SeqListClear(&mylist);
			break;
		default:
			break;
		}
	}

	SeqListDestroy(&mylist);
	printf("GoodBye.\n");
	return 0;
}
*/