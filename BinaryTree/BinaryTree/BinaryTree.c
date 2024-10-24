#include "BinaryTree.h"

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->LChild);
	PrevOrder(root->RChild);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	InOrder(root->LChild);
	printf("%c ", root->data);
	InOrder(root->RChild);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		//printf("NULL ");
		return;
	}
	PostOrder(root->LChild);
	PostOrder(root->RChild);
	printf("%c ", root->data);
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->LChild != NULL)
		{
			QueuePush(&q, front->LChild);
		}
		if (front->RChild != NULL)
		{
			QueuePush(&q, front->RChild);
		}
	}
	printf("\n");
	QueueDestroy(&q);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->LChild) + TreeSize(root->RChild) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->LChild == NULL && root->RChild == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->LChild) + TreeLeafSize(root->RChild);
}

int MaxDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return MaxDepth(root->LChild) > MaxDepth(root->RChild) ? MaxDepth(root->LChild) + 1 : MaxDepth(root->RChild) + 1;
}

void DestroyTree(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	DestroyTree(root->LChild);
	DestroyTree(root->RChild);

	free(root);
	root = NULL;
}