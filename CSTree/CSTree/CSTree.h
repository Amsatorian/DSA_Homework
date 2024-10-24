#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef char CSDataType;

typedef struct CSTreeNode
{
	CSDataType data;
	struct CSTreeNode* FirstChild;
	struct CSTreeNode* NextSibling;
}CSNode;

CSNode* CreateTree(CSDataType* a, int* pi);

void PrevOrder(CSNode* root);//ÏÈ¸ù±éÀú