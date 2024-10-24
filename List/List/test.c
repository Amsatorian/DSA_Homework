#include "List.h"

int main()
{
	//��ʼ��
	LTNode* plist = ListInit();

	//β��1��2��3��4
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	//βɾ2��
	ListPopBack(plist);
	ListPopBack(plist);

	ListPrint(plist);

	//ͷ��1��2��3��4
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	//ͷɾ3��
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);

	ListPrint(plist);

	//����
	ListInsert(plist, 1, 1);
	ListInsert(plist, 2, 2);

	ListPrint(plist);

	//ɾ��
	ListErase(plist, 1);
	ListErase(plist, 2);
	ListErase(plist, 3);
	
	ListPrint(plist);

	//��������
	ListDestroy(plist);

	printf("\n");
	printf("\n");
	printf("\n");

	//���³�ʼ��
	LTNode* plist1 = ListInit();

	ListInsert(plist1, 1, 1);
	ListInsert(plist1, 2, 2);

	ListPrint(plist1);
}