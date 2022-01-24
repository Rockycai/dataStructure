/**
 * 链表基本操作实现
 */

#include "list.h"

void InitList(SqList *L) {
		
}

int Length(SqList L) {
	return L.length;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) 
			return i + 1;	
	}
	return 0;
}

int GetElem(SqList L, int i) {
	return L.data[i];
}

bool ListInsert(SqList *L, int i, ElemType e) {

	if (i > L->length || i < 0)
		return false;
	
	for (int j = L->length; j >= i; j--) {
		L->data[j+1] = L->data[j];
	}

	L->data[i] = e;
	L->length++;
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
	free(L->data);
}