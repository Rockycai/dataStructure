/**
 * 例题 - 综合应用题
 */

#include "list.h"

/**
 * 第一题:
 * 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值
 * 空出的位置由最后一个元素填补，若顺序表为空则显示出错误信息并退出运行
 */

bool DeleteMinValue(SqList *L, int i, ElemType *e) {

	if (Empty(*L))
	{
		printf("顺序表为空退出程序 \n");
		exit(1);
	}

	if (i > L->length || i < 0)
		return false;

	if (L->length >= MAXSIZE)
		return false;
		
	*e = L->data[i];

	L->data[i] = L->data[L->length - 1];
	L->data[L->length - 1] = 0;
	L->length--;
	return true;
}

void list_example_01() {
	ElemType e;
	SqList L = TestInitData();

	printf("顺序表第一题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	DeleteMinValue(&L, LocateElem(L,  Min(&L)) - 1, &e);
	PrintList(L);
	printf("删除元素为%d \n", e);
	printf("\n");
}

// ----------------------------------------------------------------
/** 
 * 第二题
 * 设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
 */

void Reverse(SqList *L) {
	ElemType temp;

	for (int i = 0; i < L->length/2; i++) 
	{
		temp = L->data[i];
		L->data[i] = L->data[L->length - i - 1];
		L->data[L->length - i - 1] = temp;
	}
}

void list_example_02() {
	SqList L = TestInitData();
	printf("顺序表第二题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("逆置后表: ");
	Reverse(&L);
	PrintList(L);
	printf("\n");
}

// ----------------------------------------------------------------
/** 
 * 第三题
 * 对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，
 * 该算法删除线性表中所有值为x的数据元素。
 */

void DeleteXValues(SqList *L, ElemType x) {
	ElemType count = 0;
	
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] != x) 
		{
			L->data[count] = L->data[i];
			count++;
		}
	}
	L->length = count;
}

void list_example_03() {
	SqList L = TestInitData();
	printf("顺序表第三题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	DeleteXValues(&L, 71);
	PrintList(L);
	printf("\n");
}