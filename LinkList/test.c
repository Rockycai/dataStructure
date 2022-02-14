#include "LinkList.h"

void testLinkList_1() {
	LinkList L;
	InitLinkList(&L);

	LinkListInsert(L, 1, 100);
	LinkListInsert(L, 2, 200);
	LinkListInsert(L, 3, 300);

	printf("link list length %d\n", LinkListLength(L));

	PrintLinkList(L);
	LinkList p = GetLinkListElem(L, 2);
	if (p != NULL) 
	{
		printf("%d\n", p->data);
	}

	LinkList s = GetLinkListLocaleElem(L, 300);
	printf("%d\n", s->data);
	LinkListDelete(L, 2);

	PrintLinkList(L);
}