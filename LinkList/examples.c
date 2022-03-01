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
	LNode *p = (*L)->next;
	LNode *s = *L;
	LNode *q;

	while (p)
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
	if (L->next) 
	{
		Print_R(L->next);
	}

	if (L)
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
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第四题
 * 带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）
 */

void DeleteLinkListMinValue(LinkList *L) {
	LNode *pre = *L;
	LNode *p = (*L)->next;
	LNode *minpre = *L;
	LNode *min = (*L)->next;

	while (p)
	{
		if (p->data < min->data)
		{
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}

	minpre->next = min->next;
	free(min);
}

void LinkList_example_04() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 200);
	LinkListInsert(L, 2, 400);
	LinkListInsert(L, 3, 500);
	LinkListInsert(L, 4, 100);
	LinkListInsert(L, 5, 300);

	printf("链表第四题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	DeleteLinkListMinValue(&L);
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第五题
 * 带头结点的单链表就地置逆（就是辅助空间复杂度为O(1)）
 */

void ReverseLinkList_1(LinkList *L) {
	LNode *p, *r;
	p = (*L)->next;
	(*L)->next = NULL;

	while (p)
	{
		r = p->next;
		p->next = (*L)->next;
		(*L)->next = p;
		p = r;
	}
}

void ReverseLinkList_2(LinkList *L)
{
	LNode *pre, *p = (*L)->next, *r = p->next;
	p->next = NULL;

	while(r)
	{
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}

	(*L)->next = p;
}

void LinkList_example_05() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 100);
	LinkListInsert(L, 2, 200);
	LinkListInsert(L, 3, 300);
	LinkListInsert(L, 4, 400);
	LinkListInsert(L, 5, 500);

	printf("链表第五题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("1后-链表元素为: ");
	ReverseLinkList_1(&L);
	PrintLinkList(L);
	printf("2后-链表元素为: ");
	ReverseLinkList_2(&L);
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第六题
 * 有一个带头结点的单链表L，设计一个算法使其元素递增有序
 */

void SortLinkList(LinkList *L) {
	LNode *p = (*L)->next;
	LNode *pre;
	LNode *r = p->next;
	p->next = NULL;
	p = r;

	while (p) 
	{
		r = p->next;
		pre = *L;
		while ((pre->next) && (pre->next->data < p->data))
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

void LinkList_example_06() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 200);
	LinkListInsert(L, 2, 100);
	LinkListInsert(L, 3, 300);
	LinkListInsert(L, 4, 500);
	LinkListInsert(L, 5, 400);

	printf("链表第六题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	SortLinkList(&L);
	PrintLinkList(L);
	printf("\n\n");
}


// ----------------------------------------------------------------
/** 
 * 第七题
 * 设在一个带表头结点的单链表中所有元素结点的数据值无序，试编写一个函数，删除
 * 表中所有介于给定的两个值（作为函数参数给出）之间的元素的元素（若存在）
 */

void DeleteRangeValue(LinkList *L, ElemType S, ElemType T) {
	LNode *p = (*L)->next;
	LNode *pre = (*L);

	while (p) 
	{
		if (p->data > S && p->data < T)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}

void LinkList_example_07() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 200);
	LinkListInsert(L, 2, 100);
	LinkListInsert(L, 3, 300);
	LinkListInsert(L, 4, 500);
	LinkListInsert(L, 5, 400);
	LinkListInsert(L, 6, 600);
	LinkListInsert(L, 7, 800);
	LinkListInsert(L, 8, 700);

	printf("链表第七题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	DeleteRangeValue(&L, 300, 700);
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第八题
 * 给定两个单链表，编写算法找出两个链表的公共结点
 */

// TODO: 构造2个链表后还要把链在一起，暂时不做

// ----------------------------------------------------------------
/** 
 * 第九题
 * 给定一个带表头结点的单链表，设head为头指针，结点结构为(data,next),data
 * 为整型元素，next为指针，试写算法：按递增次序输出单链表中各结点的数据元素，
 * 并释放结点所占的存储空间 (要求：不允许使用数组作为辅助空间)
 */

void DeleteMinValueAndFree(LinkList *L) {
	LNode *head = (*L);
	LNode *p = (*L)->next;
	LNode *pre, *u;

	while (head->next) 
	{
		pre = head;
		p = pre->next;

		while (p->next)
		{
			if (p->next->data < pre->next->data)
				pre = p;
			p = p->next;
		}
		printf("%d ", pre->next->data);
		u = pre->next;
		pre->next = u->next;
		free(u);
	}
	free(head);
}

void LinkList_example_09() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 200);
	LinkListInsert(L, 2, 100);
	LinkListInsert(L, 3, 300);
	LinkListInsert(L, 4, 500);
	LinkListInsert(L, 5, 400);

	printf("链表第九题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("后-链表元素为: ");
	DeleteMinValueAndFree(&L);
	printf("\n\n");
}