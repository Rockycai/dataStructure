/**
 * 顺序表基本操作实现
 */

#include "list.h"

void InitList(SqList *L) {
	for (int i = 0; i < MAXSIZE; i++)
		L->data[i] = 0;
	L->length = 0;
}

int Length(SqList L) {
	return L.length;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) 
	{
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

	if (L->length >= MAXSIZE)
		return false;
	
	for (int j = L->length; j >= i; j--) 
	{
		L->data[j+1] = L->data[j];
	}

	L->data[i] = e;
	L->length++;
	return true;
}

bool ListDelete(SqList *L, int i, ElemType *e) {

	if (i > L->length || i < 0)
		return false;

	if (L->length >= MAXSIZE)
		return false;	
	
	*e = L->data[i];

	for (int j = i; j <= L->length; j++) 
	{
		L->data[j] = L->data[j+1];
	}
	L->length--;

	return true;
}

void PrintList(SqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.data[i]);
	
	printf("\n");
}

bool Empty(SqList L) {
	if (L.length == 0) {
		return true;
	}
	return false;
}

void DestroyList(SqList *L) {
	memset(L->data, 0, sizeof(ElemType) * L->length);
	L->length = 0;	
}

ElemType Min(SqList *L) {
	ElemType min = L->data[0];
	for (int i = 1; i < L->length; i++)
	{
		if (min > L->data[i]) 
		{
			min = L->data[i];
		} 
	}
	return min;
}

void add(SqList *L, ElemType e) {
	int length = Length(*L);
	ListInsert(L, length, e);
}

