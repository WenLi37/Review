#pragma once
#include "def.h"
/*	单链表	*/
/*
*	设置头节点的好处
* 1.便于首元节点的处理
* 2.便于空表和非空表的统一处理
*/

/*
* 建立单链表
*/

/*	头插法	*/
LinkList H_Creat_LinkList(void) {
	LinkList H = (LinkList)malloc(sizeof(LNode));//生成头节点
	if (H == NULL) {
		exit(-1);
	}
	H->next = NULL;//空表
	LNode* S = NULL;
	DataType x = 0;//设置数据元素类型
	scanf_s("%d", &x);
	while (x != -1) {
		S = (LinkList)malloc(sizeof(LNode));
		if (S == NULL) {
			exit(-1);
		}
		S->data = x;
		S->next = H->next;
		H->next = S;
		scanf_s("%d", &x);
	}
	return H;
}

/*	尾插法	*/
LinkList T_Creat_LinkList(void) {
	LinkList H = (LinkList)malloc(sizeof(LNode));
	if (H == NULL)exit(-1);
	H->next = NULL;
	LNode* r = H;
	int x = 0;
	scanf_s("%d", &x);
	while (x != -1) {
		LNode* S = (LinkList)malloc(sizeof(LNode));
		if (S == NULL)exit(-1);
		S->data = x;
		r->next = S;
		r = S;
		scanf_s("%d", &x);
	}
	r->next = NULL;
	return H;
}

/*
* 单链表查找
*/

/*按位查找, 带头, 从 0 开始*/
LinkList Get_LinkList(LinkList H, int k) {
	LNode* p = H;
	int j = 0;
	while (p->next != NULL && j < k) {
		p = p->next;
		j++;
	}
	if (j == k)return p;
	else return NULL;
}

/*	按值查找	*/
LNode* Locate(LinkList H, DataType x) {
	LNode* p = H->next;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}

/*	求表长	*/
int Length_LinkList(LinkList H) {
	LNode* p = H;
	int j = 0;
	while (p->next != NULL) {
		j++;
		p = p->next;
	}
	return j;
}

/*				单链表插入
* 在单链表 H 第 i 位置插入值为 x 的元素
* 1.查找第 i - 1 个结点, 若存在则继续, 否则结束(插入失败)
* 2.创建新结点
* 3.新结点next指向结点a[i]
* 4.a[i-1]节点next指向新结点
*/
bool Insert_LinkList(LinkList H, int i, DataType x) {
	LNode* P = Get_LinkList(H, i - 1);
	if (P == NULL)return false;
	LNode* S = (LinkList)malloc(sizeof(LNode));
	if (S == NULL)exit(-1);
	S->data = x;
	S->next = P->next;
	P->next = S;
	return true;
}

/*	单链表删除
* 删除第 i 个结点
* 1.查找第 i - 1 个结点, 若存在则继续, 否则结束
* 2.若存在第 i 个结点则继续, 否则结束
* 3.a[i-1]的next指向a[i+1]
* 4.释放a[i]的空间,结束
*
*/
bool Delete_LinkList(LinkList H, int i) {
	LinkList P = Get_LinkList(H, i - 1);
	if (P == NULL || P->next == NULL)return false;
	else {
		LinkList Q = P->next;
		P->next = Q->next;
		free(Q);
		return true;
	}
}
/*	单链表逆置	*/
void Reverse_LinkList(LinkList H) {
	LNode* P = H->next;
	H->next = NULL;
	while (P) {
		LNode* Q = P;
		P = P->next;
		Q->next = H->next;
		H->next = Q;
	}
}