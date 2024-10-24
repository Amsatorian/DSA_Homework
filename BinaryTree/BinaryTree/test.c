#include "BinaryTree.h"

int main()
{
	//�ֶ���ʼ��������
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

	printf("�������Ϊ:");
	PrevOrder(A);
	printf("\n");

	printf("�������Ϊ:");
	InOrder(A);
	printf("\n");

	printf("�������Ϊ:");
	PostOrder(A);
	printf("\n");

	printf("�������Ϊ:");
	LevelOrder(A);

	printf("�����Ϊ:%d\n", TreeSize(A));
	printf("Ҷ�ӽ����Ϊ:%d\n", TreeLeafSize(A));
	printf("�������Ķ�Ϊ:%d\n", MaxDepth(A));
}