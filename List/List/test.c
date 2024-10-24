#include "List.h"

int main()
{
	//初始化
	LTNode* plist = ListInit();

	//尾插1，2，3，4
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	//尾删2次
	ListPopBack(plist);
	ListPopBack(plist);

	ListPrint(plist);

	//头插1，2，3，4
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	//头删3次
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);

	ListPrint(plist);

	//插入
	ListInsert(plist, 1, 1);
	ListInsert(plist, 2, 2);

	ListPrint(plist);

	//删除
	ListErase(plist, 1);
	ListErase(plist, 2);
	ListErase(plist, 3);
	
	ListPrint(plist);

	//销毁链表
	ListDestroy(plist);

	printf("\n");
	printf("\n");
	printf("\n");

	//重新初始化
	LTNode* plist1 = ListInit();

	ListInsert(plist1, 1, 1);
	ListInsert(plist1, 2, 2);

	ListPrint(plist1);
}