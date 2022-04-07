#pragma once
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef BiTree ElemType;
typedef int DataType;

typedef struct lnode {
	DataType data;     //数据域
	struct node* next; //指针域
}LNode/*结点*/, * LinkList/*指针*/;


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
	int rear, front;//队尾队头指针
}SeqQuene;

//二叉链表
typedef struct bnode {
	DataType data;
	struct bnode* Lchild;
	struct bnode* Rchild;
}BiTNode, * BiTree;