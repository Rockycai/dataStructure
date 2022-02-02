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

// ----------------------------------------------------------------
/**
 * 第四题
 * 从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，如果s或t不合理
 * 或顺序表为空，则显示出错误信息并退出运行。
 */

bool DeleteRangeSAndT_1(SqList *L, ElemType s, ElemType t) {
	ElemType e;

	if ((s < 0) || (t < 0) || (s > t) || (L->length == 0)) 
	{
		printf("参数不符合s < t \n");
		exit(1);
	}

	for (int i = 0; i < L->length; i++)
	{
		if ((s <= L->data[i]) && (L->data[i] <= t))
		{
			/**
			 * 运行删除后顺序表中的元素会向左移动，对应的L->length也会减小
			 * 当前这一位会被其后一位替换，但是循环时这一位已经遍历过了，所以
			 * 需要在重新让当前位再次进入循环
			 */
			ListDelete(L, i, &e);
			--i; 
		}
	}
		
	return true;
}

void list_example_04() {
	SqList L = TestInitSeqData();
	printf("顺序表第四题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	DeleteRangeSAndT_1(&L, 51, 83);
	PrintList(L);
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第五题
 * 从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果
 * s或t不合理或顺序表为空，则显示出错信息并退出
 */

void DeleteRangeSAndT_2(SqList *L, ElemType s, ElemType t) {
	
	ElemType e;
	SqList Q; // 用于存放符合范围的数组
	InitList(&Q); 

	if ((s < 0) || (t < 0) || (s > t) || (L->length == 0)) 
	{
		printf("参数不符合s < t \n");
		exit(1);
	}

	for (int i = 0; i < L->length; i++) 
	{
		if ((s <= L->data[i]) && (L->data[i] <= t))
			add(&Q, L->data[i]);
	}

	for (int j = 0; j < Q.length; j++)
	{
		ListDelete(L, LocateElem(*L, Q.data[j]) - 1, &e);
	}
}

void list_example_05() {
	SqList L = TestInitData();
	printf("顺序表第五题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	DeleteRangeSAndT_2(&L, 20, 60);
	PrintList(L);
	// printf("\n");
}