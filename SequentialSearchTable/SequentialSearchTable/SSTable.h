#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MaxSize 10
#define Sentry 114514  //�ڱ���־��ȡֵ����ν

typedef int ElemType;

typedef struct SSTable
{
	ElemType* elem;
	int length;
}SSTable;

void InitTable(SSTable* T);

void AddElem(SSTable* T, ElemType elem);

int SequentialSearch(SSTable T, ElemType key);//˳�����	�±�Ϊ0��λ�ô���ڱ������Ҳ����򷵻�0
int BinarySearch(SSTable T, ElemType key);//�۰����	�±�Ϊ0��λ�ô���ڱ������Ҳ����򷵻�0