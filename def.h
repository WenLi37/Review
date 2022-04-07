#pragma once
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef BiTree ElemType;
typedef int DataType;

typedef struct lnode {
	DataType data;     //������
	struct node* next; //ָ����
}LNode/*���*/, * LinkList/*ָ��*/;


typedef struct {
	ElemType elem[MAXSIZE];
	int length;
}SeqList;

typedef struct {
	ElemType elem[MAXSIZE];
	int top;
}SeqStack;

typedef struct {
	ElemType elem[MAXSIZE];
	int rear, front;//��β��ͷָ��
}SeqQuene;

//��������
typedef struct bnode {
	DataType data;
	struct bnode* Lchild;
	struct bnode* Rchild;
}BiTNode, * BiTree;