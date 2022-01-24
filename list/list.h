/**
 * 列表头文件
 */

#ifndef LIST_H
#define LIST_H

#include "../header.h"

// 线性表顺序存储定义
typedef struct SqList {
	ElemType data[MAXSIZE];
	int length;
} SqList;

// 动态存储定义
typedef struct SeqList {
	ElemType *data;
	int length;
} SeqList;

void InitList(SqList *L);
int Length(SqList L);
int LocateElem(SqList L, ElemType e);
int GetElem(SqList L, int i);
bool ListInsert(SqList *L, int i, ElemType e);
void ListDelete(SqList *L, int i, ElemType *e);
void PrintList(SqList L);
bool Empty(SqList L);
void DestroyList(SqList *L);
void TestList(void);

#endif /* LIST_H */