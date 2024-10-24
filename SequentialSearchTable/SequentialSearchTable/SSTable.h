#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MaxSize 10
#define Sentry 114514  //哨兵标志，取值无所谓

typedef int ElemType;

typedef struct SSTable
{
	ElemType* elem;
	int length;
}SSTable;

void InitTable(SSTable* T);

void AddElem(SSTable* T, ElemType elem);

int SequentialSearch(SSTable T, ElemType key);//顺序查找	下标为0的位置存放哨兵，若找不到则返回0
int BinarySearch(SSTable T, ElemType key);//折半查找	下标为0的位置存放哨兵，若找不到则返回0