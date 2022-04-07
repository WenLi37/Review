#pragma once
#include"def.h"

/*
*	Ë³ĞòÕ»
*/

/*	ÖÃ¿ÕÕ»	*/
SeqStack* Init_Stack(void) {
	SeqStack* S = (SeqStack*)malloc(sizeof(SeqStack));
	if (S == NULL)exit(-1);
	S->top = -1;
	return S;
}

/*	ÅĞ¿ÕÕ»	*/
bool Empty_Stack(SeqStack* S) {
	if (S->top == -1)return true;
	else return false;
}

bool Push(SeqStack* S, ElemType x) {
	if (S->top == MAXSIZE - 1) {
		return false;
	} else {
		S->top++;
		S->elem[S->top] = x;
		return true;
	}
}
bool Pop(SeqStack* S, ElemType* x) {
	if (S->top == -1) {
		return false;
	} else {
		*x = S->elem[S->top];
		S->top--;
		return true;
	}
}