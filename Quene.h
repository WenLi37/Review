#pragma once
#include "def.h"

SeqQuene* Init_Quene(void) {
	SeqQuene* S = (SeqQuene*)malloc(sizeof(SeqQuene));
	if (S == NULL)exit(-1);
	S->front = S->rear = 0;
	return S;
}

bool Empty_Quene(SeqQuene* S) {
	if (S->front == S->rear) {
		return true;
	} else {
		return false;
	}
}

/*
* ���
*/
bool enQuene(SeqQuene* S, int x) {
	if ((S->rear + 1) % MAXSIZE == S->front) {
		return false;//����
	} else {//δ��, ���ƶ�ָ��, �ٴ���Ԫ��
		S->rear = (S->rear + 1) % MAXSIZE;
		S->elem[S->rear] = x;
		return true;
	}
}

/*
* ����
*/
bool deQuene(SeqQuene* S, int x) {
	if (Empty_Quene(S)) {
		return false;//�ӿ�
	} else {
		S->front = (S->front + 1) % MAXSIZE;
		x = S->elem[S->front];
		return true;
	}
}