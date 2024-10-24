#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* LChild;
	struct BinaryTreeNode* RChild;
	BTDataType data;
}BTNode;

void PrevOrder(BTNode* root);//�������
void InOrder(BTNode* root);//�������
void PostOrder(BTNode* root);//�������
void LevelOrder(BTNode* root);//�������

int TreeSize(BTNode* root);//�����
int TreeLeafSize(BTNode* root);//Ҷ�ӽ����
int MaxDepth(BTNode* root);//�������Ķ�

void DestroyTree(BTNode* root);//�ݻ���