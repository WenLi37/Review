#pragma once
#include "def.h"

void Init_SeqList(SeqList* L) {
	L->length = 0;
}

/*
*	˳������
* 1.�жϱ��Ƿ���
* 2.����λ���Ƿ�Ϸ�
* 3.��a[n] - a[i]Ԫ�شӺ���ǰ���к���
* 4.���������Ԫ�ط��ڿճ���λ��
* 5.�޸ı�
*/
bool Insert_SeqList(SeqList* L, int i, ElemType x) {
	if (L->length == MAXSIZE)return false;//����
	if (i < 1 || i > L->length + 1)return false;//����λ�ò��Ϸ�
	for (int j = L->length; j >= i; j--) {
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i] = x;
	L->length++;
	return true;
}

/*
* ���Ա��а�λ����
* ˳���� 1 ��ʼ
*/
ElemType SeqList_Get_Elem(SeqList* L, int i) {
	if (i < 1 || i > L->length)return -1;
	return L->elem[i];
}

/*
*	˳���ɾ��
* 1.�ж�λ���Ƿ�Ϸ�
* 2.�洢Ҫɾ����Ԫ��
* 3.��a[i+1] - a[n]����ǰ��
* 4.�޸ı�
*/
bool Delete_SeqList(SeqList* L, int i, ElemType* e) {
	if (i < 1 || i > L->length)return false;
	*e = L->elem[i];
	for (int j = i; j < L->length; j++) {
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
	return true;
}

/*
* ˳���ֵ����
*/
int Location_SeqList(SeqList* L, ElemType x) {
	int i = 1;
	while (i <= L->length && L->elem[i] != x) {
		i++;
	}
	if (i > L->length)return 0;//����ʧ��
	else return i;
}

