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

void PrevOrder(BTNode* root);//先序遍历
void InOrder(BTNode* root);//中序遍历
void PostOrder(BTNode* root);//后序遍历
void LevelOrder(BTNode* root);//层序遍历

int TreeSize(BTNode* root);//结点数
int TreeLeafSize(BTNode* root);//叶子结点数
int MaxDepth(BTNode* root);//二叉树的度

void DestroyTree(BTNode* root);//摧毁树