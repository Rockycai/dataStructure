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
	int MaxSize, length;
} SeqList;

void InitList(SqList *L);
int Length(SqList L);
int LocateElem(SqList L, ElemType e);
int GetElem(SqList L, int i);
bool ListInsert(SqList *L, int i, ElemType e);
bool ListDelete(SqList *L, int i, ElemType *e);
void PrintList(SqList L);
bool Empty(SqList L);
void DestroyList(SqList *L);

// 在顺序表末尾添加元素
void add(SqList *L, ElemType e);

void InitSeqList(SeqList *L);
int SeqLength(SeqList L);
int LocateSeqElem(SeqList L, ElemType e);
int GetSeqElem(SeqList L, int i);
bool ListSeqInsert(SeqList *L, int i, ElemType e);
bool ListSeqDelete(SeqList *L, int i, ElemType *e);
void PrintSeqList(SeqList L);
bool EmptySeq(SeqList L);
void DestroySeqList(SeqList *L);

/**
 * 测试用列 
 */
void TestList_1(void);
void TestList_2(void);
void TestList_3(void);
SqList TestInitData(void);
SqList TestInitSeqData_1(void);
SqList TestInitSeqData_2(void);
SqList TestInitData_1(void);

ElemType Min(SqList *L);
void Reverse(SqList *L);

void list_example_01(void);
void list_example_02(void);
void list_example_03(void);
void list_example_04(void);
void list_example_05(void);
void list_example_06(void);
void list_example_07(void);
void list_example_08(void);
void list_example_09(void);
void list_example_10(void);
void list_example_11(void);
void list_example_12(void);
void list_example_13(void);

#endif /* LIST_H */