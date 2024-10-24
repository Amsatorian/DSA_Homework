#include "List.h"

LTNode* ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}


int CountNode(LTNode* phead)
{
	int count = 0;
	LTNode* cur = phead->next;
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

void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void ListPushBack(LTNode* phead, LTDateType x)
{
	/*assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;*/

	ListInsert(phead, CountNode(phead) + 1, x);//¸´ÓÃListInsert
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* tailPrev = tail->prev;
	tailPrev->next = phead;
	phead->prev = tailPrev;
	free(tail);
}

void ListPushFront(LTNode* phead, LTDateType x)
{
	/*assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	next->prev = newnode;
	newnode->next = next;*/

	ListInsert(phead, 1, x);//¸´ÓÃListInsert
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	LTNode* nextNext = next->next;
	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}


void ListInsert(LTNode* phead, int pos, LTDateType x)
{
	assert(phead);
	assert(pos <= CountNode(phead) + 1);
	LTNode* newnode = BuyListNode(x);
	LTNode* cur = phead;
	for (int i = 0; i < pos - 1; i++)
	{
		cur = cur->next;
	}
	LTNode* curNext = cur->next;
	cur->next = newnode;
	newnode->prev = cur;
	curNext->prev = newnode;
	newnode->next = curNext;
}

void ListErase(LTNode* phead, int pos)
{
	assert(phead);
	assert(phead->next != phead);
	assert(pos <= CountNode(phead));
	LTNode* cur = phead;
	for (int i = 0; i < pos; i++)
	{
		cur = cur->next;
	}
	LTNode* curPrev = cur->prev;
	LTNode* curNext = cur->next;
	curPrev->next = curNext;
	curNext->prev = curPrev;
	free(cur);
}


void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* curNext = cur->next;
		free(cur);
		cur = curNext;
	}
	free(phead);
}