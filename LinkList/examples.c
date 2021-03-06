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
	LNode *p, *pre, *u;

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

// ----------------------------------------------------------------
/** 
 * 第十题
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A表中含有原表
 * 中序号为奇数的元素，而B表中含有原表中序号为偶数的元素，且保持其相对顺序不
 * 变
 */

LinkList DiscardLinkList_1(LinkList *L) {
	int i = 0;
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *ra = *L;
	LNode *rb = B;
	LNode *p = (*L)->next;

	(*L)->next = NULL;

	while (p)
	{
		i++;
		if (i % 2 == 0)
		{
			rb->next = p;
			rb = p;
		}
		else
		{
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;

	return B;
}

void LinkList_example_10() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 1);
	LinkListInsert(L, 2, 2);
	LinkListInsert(L, 3, 3);
	LinkListInsert(L, 4, 4);
	LinkListInsert(L, 5, 5);
	LinkListInsert(L, 6, 6);
	LinkListInsert(L, 7, 7);
	LinkListInsert(L, 8, 8);

	printf("链表第十题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("1-链表元素为: ");
	PrintLinkList(DiscardLinkList_1(&L));
	printf("2-链表元素为: ");
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第十一题
 * 设C={a1,b1,a2,b2,...,an,bn}为线性表，采用带头结点的hc单链表存放，设计
 * 一个就地算法，将其拆分为2个线性表，使得A={a1,a2,...,an}, b={bn,...,b2,b1}
 */

LinkList DiscardLinkList_2(LinkList *L) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *q;
	LNode *p = (*L)->next;
	LNode *ra = (*L);

	while (p) 
	{
		ra->next = p;
		ra = p;
		p = p->next;

		if (p)
			q = p->next;
		p->next = B->next;
		B->next = p;
		p = q;
	}
	ra->next = NULL;
	return B;
}

void LinkList_example_11() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 1);
	LinkListInsert(L, 2, 2);
	LinkListInsert(L, 3, 3);
	LinkListInsert(L, 4, 4);
	LinkListInsert(L, 5, 5);
	LinkListInsert(L, 6, 6);
	LinkListInsert(L, 7, 7);
	LinkListInsert(L, 8, 8);

	printf("链表第十一题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("1-链表元素为: ");
	PrintLinkList(DiscardLinkList_2(&L));
	printf("2-链表元素为: ");
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第十二题
 * 在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法
 * 去掉数值相同的元素，使表中不再有重复的元素，例如（7,10,10,21,30,42,42,42
 * ,51,70）将变为（7，10，21，30，42，51，70）
 */

void DeleteLinkDuplicateValue(LinkList *L) {
	LNode *p = (*L)->next;
	LNode *q = (*L);

	while (p->next) 
	{
		q = p->next;
		if (p->data == q->data) 
		{
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
}

void LinkList_example_12() {
	LinkList L;

	InitLinkList(&L);
	LinkListInsert(L, 1, 7);
	LinkListInsert(L, 2, 10);
	LinkListInsert(L, 3, 10);
	LinkListInsert(L, 4, 21);
	LinkListInsert(L, 5, 30);
	LinkListInsert(L, 6, 42);
	LinkListInsert(L, 7, 42);
	LinkListInsert(L, 8, 42);
	LinkListInsert(L, 9, 51);
	LinkListInsert(L, 10, 70);

	printf("链表第十二题\n");
	printf("原-链表元素为: ");
	PrintLinkList(L);
	printf("链表元素为: ");
	DeleteLinkDuplicateValue(&L);
	PrintLinkList(L);
	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第十三题
 * 假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。请编写算法将这两个
 * 单链表归并为一个按元素值递减次序排列的单链表，并要求利用原来两个单链表的结点
 * 存放归并后的单链表
 */

void MergeLinkList(LinkList *La, LinkList *Lb) {
	LNode *r, *pa = (*La)->next, *pb = (*Lb)->next;
	(*La)->next = NULL;

	while (pa && pb)
	{
		if (pa->data <= pb->data) 
		{
			r = pa->next;
			pa->next = (*La)->next;
			(*La)->next = pa;
			pa = r;
		}
		else
		{
			r = pb->next;
			pb->next = (*La)->next;
			(*La)->next = pb;
			pb = r;
		}
	}

	if (pa)
		pb = pa;

	while (pb)
	{
		r = pb->next;
		pb->next = (*La)->next;
		(*La)->next = pb;
		pb = r;
	}

	free(*Lb);
}

void LinkList_example_13() {
	LinkList La, Lb;
	InitLinkList(&La);
	InitLinkList(&Lb);

	LinkListInsert(La, 1, 1);
	LinkListInsert(La, 2, 3);
	LinkListInsert(La, 3, 5);
	LinkListInsert(La, 4, 7);
	LinkListInsert(La, 5, 9);

	LinkListInsert(Lb, 1, 2);
	LinkListInsert(Lb, 2, 4);
	LinkListInsert(Lb, 3, 6);
	LinkListInsert(Lb, 4, 8);
	LinkListInsert(Lb, 5, 10);

	printf("链表第十三题\n");
	printf("1-链表元素为: ");
	PrintLinkList(La);
	printf("2-链表元素为: ");
	PrintLinkList(Lb);
	printf("合并后链表为: ");
	MergeLinkList(&La, &Lb);
	PrintLinkList(La);

	printf("\n\n");
}

// ----------------------------------------------------------------
/** 
 * 第十四题
 * 设A和B是两个单链表（带头结点）,其中元素递增有序。设计一个算法从A和B中的公
 * 共元素产生单链表C，要求不破坏A，B的结点。
 */

LinkList MergeCommon(LinkList A, LinkList B) {
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r, *s;

	LinkList C = (LinkList)malloc(sizeof(LNode));
	r = C;

	while (p && q) {
		if (p->data < q->data) {
			p = p->next;
		} else if (p->data > q->data) {
			q = q->next;
		} else {
			s = (LNode *)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
	return C;
}

void LinkList_example_14() {
	LinkList La, Lb;
	InitLinkList(&La);
	InitLinkList(&Lb);

	LinkListInsert(La, 1, 1);
	LinkListInsert(La, 2, 2);
	LinkListInsert(La, 3, 5);
	LinkListInsert(La, 4, 8);
	LinkListInsert(La, 5, 9);

	LinkListInsert(Lb, 1, 2);
	LinkListInsert(Lb, 2, 4);
	LinkListInsert(Lb, 3, 6);
	LinkListInsert(Lb, 4, 8);
	LinkListInsert(Lb, 5, 10);

	printf("链表第十四题\n");
	printf("1-链表元素为: ");
	PrintLinkList(La);
	printf("2-链表元素为: ");
	PrintLinkList(Lb);
	printf("合并后链表为: ");
	PrintLinkList(MergeCommon(La,Lb));

	printf("\n\n");
}