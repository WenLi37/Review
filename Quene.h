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
* 入队
*/
bool enQuene(SeqQuene* S, int x) {
	if ((S->rear + 1) % MAXSIZE == S->front) {
		return false;//队满
	} else {//未满, 先移动指针, 再存入元素
		S->rear = (S->rear + 1) % MAXSIZE;
		S->elem[S->rear] = x;
		return true;
	}
}

/*
* 出队
*/
bool deQuene(SeqQuene* S, int x) {
	if (Empty_Quene(S)) {
		return false;//队空
	} else {
		S->front = (S->front + 1) % MAXSIZE;
		x = S->elem[S->front];
		return true;
	}
}