#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SLTNode;

SLTNode* SListInit();
SLTNode* BuySListNode(SLTDateType x);

int CountNode(SLTNode* phead);//��������

void SListPrint(SLTNode* phead);

void SListInsert(SLTNode* phead, int pos, SLTDateType x);//����x������x�ǵ�pos����������
void SListPushFront(SLTNode* phead, SLTDateType x);//ͷ��
void SListPushBack(SLTNode* phead, SLTDateType x);//β��

void SListErase(SLTNode* phead, int pos);//ɾ��posλ�õĽ��
void SListPopBack(SLTNode* phead);//ͷɾ
void SListPopFront(SLTNode* phead);//βɾ