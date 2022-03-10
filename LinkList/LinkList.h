#ifndef LINKLIST_H
#define LINKLIST_H

#include "../header.h"

// 单链表
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

typedef struct DNode {
	ElemType data;
	struct DNode *prior, *next;
} DNode, *DLinkList;

// 单链表操作
void InitLinkList(LinkList *L);
int LinkListLength(LinkList L);
bool LinkListInsert(LinkList L, int i, ElemType e);
LNode *GetLinkListElem(LinkList L, int i);
LNode *GetLinkListLocaleElem(LinkList L, ElemType e);
bool LinkListDelete(LinkList L, int i);
void PrintLinkList(LinkList L);

// 双链表操作
void InitDLinkList(DLinkList *DL);
bool DLinkListInsert(DLinkList DL, int i, ElemType e);
bool DLinkListDelete(DLinkList DL, int i);
void PrintDList(DLinkList DL);

void testLinkList_1(void);
void testLinkList_2(void);

void LinkList_example_01(void);
void LinkList_example_02(void);
void LinkList_example_03(void);
void LinkList_example_04(void);
void LinkList_example_05(void);
void LinkList_example_06(void);
void LinkList_example_07(void);
void LinkList_example_09(void);
void LinkList_example_10(void);
void LinkList_example_11(void);
void LinkList_example_12(void);
void LinkList_example_13(void);

#endif /* LINKLIST_H */