#include "SList.h"

int main()
{
	SLTNode* plist = SListInit();

	//β��1��2��3��4
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);
	SListPushBack(plist, 4);

	SListPrint(plist);

	//ͷ��1��2��3��4
	SListPushFront(plist, 1);
	SListPushFront(plist, 2);
	SListPushFront(plist, 3);
	SListPushFront(plist, 4);

	SListPrint(plist);

	//����
	SListInsert(plist, 1, 1);
	SListInsert(plist, 2, 2);
	SListInsert(plist, 3, 3);
	SListInsert(plist, 4, 4);

	SListPrint(plist);

	//ɾ��
	SListErase(plist, 3);
	SListPopBack(plist);
	SListPopFront(plist);

	SListPrint(plist);

	return 0;
}