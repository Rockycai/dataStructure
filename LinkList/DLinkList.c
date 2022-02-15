#include "LinkList.h"

void InitDLinkList(DLinkList *DL) {
	*DL = (DLinkList)malloc(sizeof(struct LNode));
	if(!*DL)
		exit(1);
	
	(*DL)->next = (*DL)->prior = *DL;
}

bool DLinkListInsert(DLinkList DL, int i, ElemType e) {
	int j = 0;

	DLinkList p = DL;

	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}

    if(!p || (j>i-1)) 
	{
        return false;
    }

	DLinkList s = (DLinkList)malloc(sizeof(DNode));
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;

	return true;
}

bool DLinkListDelete(DLinkList DL, int i) {
	int j = 0;
	DLinkList p = DL;
	DLinkList s;

	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}

    if(!p->next || j>i-1)
        return false;	
	
	s = p->next;
	p->next = s->next;
	s->next->prior = p;

	free(s);
	return true;
}

void PrintDList(DLinkList DL) {

	DLinkList p = DL->next;

	while (p != DL)
	{
		printf("%d \n", p->data);
		p = p->next;
	}
}

