/**
 * 链表基本操作实现
 */

#include "list.h"

void InitList(SqList *L) {
	L = (SqList *)malloc(sizeof(SqList));
	if(!L) 
		exit(1);
}

int Length(SqList L) {
	return L.length;
}

int LocateElem(SqList L, ElemType e) {

	return 0;
}

int GetElem(SqList L, int i) {
	return L.data[i];
}

bool ListInsert(SqList *L, int i, ElemType e) {
	return true;
}

void ListDelete(SqList *L, int i, ElemType *e) {

}

void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	
	printf("\n");
}

bool Empty(SqList L) {

	return false;
}

void DestroyList(SqList *L) {
	free(L);
}