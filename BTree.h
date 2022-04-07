#pragma once
#include "def.h"
#include "Stack.h"

/*
* 创建二叉链表
*
*/
bool Create_BiTree(BiTree* root) {
	DataType ch = 0;
	ch = getchar();
	if (ch == '#') {
		*root = NULL;
		return false;
	} else {
		*root = (BiTree)malloc(sizeof(BiTNode));
		if (*root == NULL)exit(-1);
		(*root)->data = ch;
		Create_BiTree(&(*root)->Lchild);
		Create_BiTree(&(*root)->Rchild);
	}
}

bool visit(BiTree B) {
	if (B == NULL)return false;
	else {
		printf("%d ", B->data);
		return true;
	}
}

bool PreOrder(BiTree root) {
	SeqStack* S = Init_Stack();
	BiTree P = root;
	if (root == NULL)return false;
	while (P != NULL || !Empty_Stack(S)) {
		while (P != NULL) {
			visit(P);
			Push(S, P);
			P = P->Lchild;
		}
		if (!Empty_Stack(S)) {
			Pop(S, &P);
			P = P->Rchild;
		}
	}
	return true;
}

bool InOrder(BiTree root) {
	SeqStack* S = Init_Stack();
	BiTree P = root;
}