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

void InitLinkList(LinkList *L);
int LinkListLength(LinkList L);
bool LinkListInsert(LinkList L, int i, ElemType e);
LNode *GetLinkListElem(LinkList L, int i);
LNode *GetLinkListLocaleElem(LinkList L, ElemType e);
bool LinkListDelete(LinkList L, int i);
void PrintLinkList(LinkList L);

void testLinkList_1(void);

#endif /* LINKLIST_H */