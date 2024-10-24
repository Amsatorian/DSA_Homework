#include "SList.h"

SLTNode* SListInit()
{
	//创建哨兵位头节点
	SLTNode* phead = (SLTNode*)malloc(sizeof(SLTNode));
	phead->next = phead;
	return phead;
}

SLTNode* BuySListNode(SLTDateType x)
{
	//创建一个新的节点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	return newnode;
}


int CountNode(SLTNode* phead)
{
	int count = 0;
	SLTNode* cur = phead->next;
	if (cur == phead)
	{
		return count;
	}
	else
	{
		while (cur != phead)
		{
			cur = cur->next;
			count++;
		}
		return count;
	}
}


void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void SListInsert(SLTNode* phead, int pos, SLTDateType x)
{
	assert(pos <= CountNode(phead) + 1);
	SLTNode* newnode = BuySListNode(x);
	SLTNode* posPrev = phead;
	for (int i = 0; i < pos - 1; i++)
	{
		posPrev = posPrev->next;
	}
	newnode->next = posPrev->next;
	posPrev->next = newnode;
}

void SListPushFront(SLTNode* phead, SLTDateType x)
{
	/*SLTNode* newnode = BuySListNode(x);
	newnode->next = phead->next;
	phead->next = newnode;*/

	SListInsert(phead, 1, x);//复用SListInsert
}

void SListPushBack(SLTNode* phead, SLTDateType x)
{
	/*SLTNode* newnode = BuySListNode(x);
	SLTNode* tail = phead->next;
	while (tail->next != phead)
	{
		tail = tail->next;
	}
	newnode->next = phead;
	tail->next = newnode;*/

	SListInsert(phead, CountNode(phead) + 1, x);//复用SListInsert
}


void SListErase(SLTNode* phead, int pos)
{
	assert(phead->next != phead);
	assert(pos <= CountNode(phead));
	SLTNode* posPrev = phead;
	for (int i = 0; i < pos - 1; i++)
	{
		posPrev = posPrev->next;
	}
	SLTNode* cur = posPrev->next;
	posPrev->next = cur->next;
	free(cur);
}

void SListPopFront(SLTNode* phead)
{
	assert(phead->next != phead);
	SLTNode* pheadNext = phead->next;
	phead->next = phead->next->next;
	free(pheadNext);
}

void SListPopBack(SLTNode* phead)
{
	assert(phead->next != phead);
	SLTNode* tailPrev = phead;
	SLTNode* tail = phead->next;
	while (tail->next != phead)
	{
		tailPrev = tailPrev->next;
		tail = tail->next;
	}
	tailPrev->next = phead;
	free(tail);
}