#pragma once
#include "def.h"

void Init_SeqList(SeqList* L) {
	L->length = 0;
}

/*
*	顺序表插入
* 1.判断表是否满
* 2.插入位置是否合法
* 3.将a[n] - a[i]元素从后向前进行后移
* 4.将所插入的元素放于空出的位置
* 5.修改表长
*/
bool Insert_SeqList(SeqList* L, int i, ElemType x) {
	if (L->length == MAXSIZE)return false;//表满
	if (i < 1 || i > L->length + 1)return false;//插入位置不合法
	for (int j = L->length; j >= i; j--) {
		L->elem[j + 1] = L->elem[j];
	}
	L->elem[i] = x;
	L->length++;
	return true;
}

/*
* 线性表中按位查找
* 顺序表从 1 开始
*/
ElemType SeqList_Get_Elem(SeqList* L, int i) {
	if (i < 1 || i > L->length)return -1;
	return L->elem[i];
}

/*
*	顺序表删除
* 1.判断位置是否合法
* 2.存储要删除的元素
* 3.将a[i+1] - a[n]依次前移
* 4.修改表长
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
* 顺序表按值查找
*/
int Location_SeqList(SeqList* L, ElemType x) {
	int i = 1;
	while (i <= L->length && L->elem[i] != x) {
		i++;
	}
	if (i > L->length)return 0;//查找失败
	else return i;
}

