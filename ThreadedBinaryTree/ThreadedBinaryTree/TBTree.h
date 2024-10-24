#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char BTDataType;

//Tag == 0ָ���ӣ�Tag == 1ָ������
typedef struct ThreadedBinaryTreeNode
{
	BTDataType data;
	struct ThreadedBinaryTreeNode* LChild;
	struct ThreadedBinaryTreeNode* RChild;
	int LTag, RTag;
}BTNode;

BTNode* CreateTree(BTDataType* a, int* pi);

void visit(BTNode* root);
void InThread(BTNode* root);
void CreateInThread(BTNode* root);

BTNode* FirstNode(BTNode* root);
BTNode* NextNode(BTNode* root);
void InOrder(BTNode* root);

BTNode* LastNode(BTNode* root);
BTNode* PrevNode(BTNode* root);
void RevInOrder(BTNode* root);