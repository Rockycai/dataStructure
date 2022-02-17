/**
 * 例题 - 综合应用题
 */

#include "LinkList.h"

/**
 * 第一题:
 * 设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点
 */

void DeleteLinkListXValues(LinkList *L, ElemType e) {
	LNode *p;
	if (*L == NULL) 
		return;

	if ((*L)->data == e) 
	{
		p = *L;
		*L = (*L)->next;
		free(p);
		DeleteLinkListXValues(&(*L), e);
	}
	else
		DeleteLinkListXValues(&(*L)->next, e);
}

void LinkList_example_01() {
	LNode *s;
	int x[5] = {1, 2, 2, 4, 5};
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	for (int i = 0; i < sizeof(x)/sizeof(int); i++)	
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x[i];
		s->next = L->next;
		L->next = s;
	}

	printf("链表第一题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	DeleteLinkListXValues(&L, 2);
	printf("后-链表元素为: ");
	PrintLinkList(L);
	printf("\n");
}

// ----------------------------------------------------------------
/** 
 * 第二题
 * 在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点
 * 不唯一。
 */

void DeleteHeadLNodeXValues(LinkList *L, ElemType e) {
	LinkList p = (*L)->next;
	LinkList s = *L;
	LinkList q;

	while (p!= NULL)
	{
		if (p->data == e) 
		{
			q = p;
			p = p->next;
			s->next = p;
			free(q);
		}
		else
		{
			s = p;
			p = p->next;
		}
	}	
}

void LinkList_example_02() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 100);
	LinkListInsert(L, 2, 200);
	LinkListInsert(L, 3, 100);
	LinkListInsert(L, 4, 300);
	LinkListInsert(L, 5, 400);

	printf("链表第二题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	DeleteHeadLNodeXValues(&L, 100);
	PrintLinkList(L);
	printf("\n");
}

// ----------------------------------------------------------------
/** 
 * 第三题
 * 设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值
 */

void Print_R(LinkList L) {
	if (L->next != NULL) 
	{
		Print_R(L->next);
	}

	if (L != NULL)
		printf("%d ", L->data);
}

void LinkList_example_03() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 100);
	LinkListInsert(L, 2, 200);
	LinkListInsert(L, 3, 300);
	LinkListInsert(L, 4, 400);
	LinkListInsert(L, 5, 500);

	printf("链表第三题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	// 这里是带头结点，所以要把头节点去掉
	Print_R(L->next);
	printf("\n");
}
