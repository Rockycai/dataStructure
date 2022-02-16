#include "LinkList.h"

void InitLinkList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(struct LNode));
	if(!*L)
		exit(1);
	
	(*L)->next = NULL;
}

int LinkListLength(LinkList L) {
	int i = 0;
	LinkList p = L->next;

	while(p != NULL) {
		p = p->next;
		i++;
	}

	return i;
}

LNode *GetLinkListElem(LinkList L, int i) {
	int j = 0;
	LinkList p = L;

	if (i == 0) 
	{
		return L;		
	}

	if (i < 1)
	{
		return NULL;
	}

	if (i > LinkListLength(L))
	{
		return NULL;
	}

	while(p && j < i)
	{
		p = p->next;
		j++;
	}

	return p;
}

LNode *GetLinkListLocaleElem(LinkList L, ElemType e) {
	LinkList p = L;

	while(p != NULL && p->data != e)
		p = p->next;

	return p;
}

bool LinkListInsert(LinkList L, int i, ElemType e) {
	int j = 0;

	LinkList p = L;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

    if(!p || (j>i-1)) 
	{
        return false;
    }

	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

bool LinkListDelete(LinkList L, int i) {
	int j = 0;
	LinkList p = L;
	LinkList s;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

    if(!p->next || j>i-1)
        return false;

	s = p->next;
	p->next = s->next;
	free(s);
	return true;
}

void PrintLinkList(LinkList L) {
	LinkList p = L;

	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}