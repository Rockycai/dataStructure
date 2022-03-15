#include "stack.h"

void InitStack(SqStack *S) {
	S->top = -1;
}

bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return false;
	return true;
}

bool GetTop(SqStack S, ElemType *x) {
	if (StackEmpty(S) == -1)
		return false;
	*x = S.data[S.top];	
	return true;
}

bool Push(SqStack *S, ElemType x) {
	if (S->top == MAXSIZE - 1)
		return false;
	
	S->data[S->top++] = x;
	return true;
}

bool Pop(SqStack *S, ElemType *x) {
	if (StackEmpty(*S) == -1)
		return false;	
	*x = S->data[S->top--];
	return true;
}

void DestroyStack(SqStack *S) {
	
}