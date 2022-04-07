#pragma once
#include "def.h"
/*	������	*/
/*
*	����ͷ�ڵ�ĺô�
* 1.������Ԫ�ڵ�Ĵ���
* 2.���ڿձ�ͷǿձ��ͳһ����
*/

/*
* ����������
*/

/*	ͷ�巨	*/
LinkList H_Creat_LinkList(void) {
	LinkList H = (LinkList)malloc(sizeof(LNode));//����ͷ�ڵ�
	if (H == NULL) {
		exit(-1);
	}
	H->next = NULL;//�ձ�
	LNode* S = NULL;
	DataType x = 0;//��������Ԫ������
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

/*	β�巨	*/
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
* ���������
*/

/*��λ����, ��ͷ, �� 0 ��ʼ*/
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

/*	��ֵ����	*/
LNode* Locate(LinkList H, DataType x) {
	LNode* p = H->next;
	while (p != NULL && p->data != x) {
		p = p->next;
	}
	return p;
}

/*	���	*/
int Length_LinkList(LinkList H) {
	LNode* p = H;
	int j = 0;
	while (p->next != NULL) {
		j++;
		p = p->next;
	}
	return j;
}

/*				���������
* �ڵ����� H �� i λ�ò���ֵΪ x ��Ԫ��
* 1.���ҵ� i - 1 �����, �����������, �������(����ʧ��)
* 2.�����½��
* 3.�½��nextָ����a[i]
* 4.a[i-1]�ڵ�nextָ���½��
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

/*	������ɾ��
* ɾ���� i �����
* 1.���ҵ� i - 1 �����, �����������, �������
* 2.�����ڵ� i ����������, �������
* 3.a[i-1]��nextָ��a[i+1]
* 4.�ͷ�a[i]�Ŀռ�,����
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
/*	����������	*/
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