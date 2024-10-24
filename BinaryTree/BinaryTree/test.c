#include "BinaryTree.h"

int main()
{
	//手动初始化二叉树
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	assert(A);
	A->data = 'A';
	A->LChild = NULL;
	A->RChild = NULL;

	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	assert(B);
	B->data = 'B';
	B->LChild = NULL;
	B->RChild = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	assert(C);
	C->data = 'C';
	C->LChild = NULL;
	C->RChild = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	assert(D);
	D->data = 'D';
	D->LChild = NULL;
	D->RChild = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	assert(E);
	E->data = 'E';
	E->LChild = NULL;
	E->RChild = NULL;

	BTNode* F = (BTNode*)malloc(sizeof(BTNode));
	assert(F);
	F->data = 'F';
	F->LChild = NULL;
	F->RChild = NULL;

	BTNode* G = (BTNode*)malloc(sizeof(BTNode));
	assert(G);
	G->data = 'G';
	G->LChild = NULL;
	G->RChild = NULL;

	A->LChild = B;
	A->RChild = C;
	B->LChild = D;
	B->RChild = E;
	C->RChild = F;
	E->LChild = G;

	printf("先序遍历为:");
	PrevOrder(A);
	printf("\n");

	printf("中序遍历为:");
	InOrder(A);
	printf("\n");

	printf("后序遍历为:");
	PostOrder(A);
	printf("\n");

	printf("层序遍历为:");
	LevelOrder(A);

	printf("结点数为:%d\n", TreeSize(A));
	printf("叶子结点数为:%d\n", TreeLeafSize(A));
	printf("二叉树的度为:%d\n", MaxDepth(A));
}