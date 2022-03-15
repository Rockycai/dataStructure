/**
 * 列表头文件
 */

#ifndef STACK_H
#define STACK_H

#include "../header.h"

typedef struct LinkNode {
	ElemType data;
	struct LinkNode *next;
} *LiStack;

typedef struct SqStack {
	ElemType data[MAXSIZE];
	int top;
} SqStack;

void InitStack(SqStack *S);
bool StackEmpty(SqStack S);
bool Push(SqStack *S, ElemType x);
bool Pop(SqStack *S, ElemType *x);
bool GetTop(SqStack S, ElemType *x);
void DestroyStack(SqStack *S);

#endif /* STACK_H */