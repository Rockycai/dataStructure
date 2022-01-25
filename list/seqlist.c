/**
 * 链表基本操作实现 (使用动态数组版)
 */

#include "list.h"

void InitSeqList(SeqList *L) {
	L->data = (ElemType *)malloc(sizeof(ElemType) * INITSIZE);
	if (L->data == NULL) 
		exit(1);
}

int SeqLength(SeqList L) {
	return L.length;
}

int LocateSeqElem(SeqList L, ElemType e) {

	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;

	return 0;
}

int GetSeqElem(SeqList L, int i) {
	return L.data[i];
}

bool ListSeqInsert(SeqList *L, int i, ElemType e) {

	if (i < 0 || i > L->length)
		return false;
	
	if (L->length >= INITSIZE)
		return false;

	for (int j = L->length; j >= i; j--) {
		L->data[j+1] = L->data[j];
	}

	L->data[i] = e;
	L->length++;

	return true;
}

bool ListSeqDelete(SeqList *L, int i, ElemType *e) {

	if (i < 0 || i > L->length)
		return false;
	
	if (L->length >= INITSIZE)
		return false;

	*e = L->data[i];

	for (int j = i; j <= L->length; j++)
		L->data[j] = L->data[j+1];
	
	L->length--;
	return true;
}

void PrintSeqList(SeqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	
	printf("\n");	
}

bool EmptySeq(SeqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}

void DestroySeqList(SeqList *L) {
	free(L->data);
}
