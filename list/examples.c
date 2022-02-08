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
	SqList L = TestInitSeqData_1();
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

/**
 * 这里解题思路和书本答案差距较大。这里我使用一个临时空间用来存储符合元素的
 * 值，符合要求就把元素插入数组尾部，在遍历临时数组和顺序表中的值做对比合适
 * 就删除，我这里因为用的都是已经实现的算法，里面循环比较多，算法时间复杂度
 * 和空间复杂度都高于书中给的答案对效率有要求的话建议书中答案来实现。 
 */
void DeleteRangeSAndT_2(SqList *L, ElemType s, ElemType t) {
	
	ElemType e;
	SqList Q; // 用于存放符合范围的数组
	InitList(&Q); // 必须要初始化不如会出现垃圾值

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

// 书中算法实现
bool Del_s_t(SqList *L, ElemType s, ElemType t) {
	int k = 0;
	if (L->length == 0 || s >= t)
		return false;
	
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] >= s && L->data[i] <= t)
			k++;
		else
			L->data[i-k] = L->data[i];
	}

	L->length-=k;
	
	return true;
}

void list_example_05() {
	SqList L = TestInitData();
	SqList Q = TestInitData();
	printf("顺序表第五题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表- \n");
	printf("算法1: ");
	DeleteRangeSAndT_2(&L, 20, 60);
	PrintList(L);
	printf("算法2: ");
	Del_s_t(&Q, 20, 60);
	PrintList(Q);
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第六题
 * 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
 */

bool DeleteDuplicateElements(SqList *L) {

	ElemType e;

	if (L->length == 0)
		return false;
	
	for (int i = 0; i < L->length; i++) 
	{
		if (L->data[i] == L->data[i + 1]) 
		{
			ListDelete(L, i, &e);
			--i;
		}
	}

	return true;
}

void list_example_06() {
	SqList L = TestInitData_1();
	printf("顺序表第六题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	DeleteDuplicateElements(&L);
	PrintList(L);
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第七题
 * 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
 */

SqList merge(SqList S, SqList T) {
	SqList L;

	if (S.length + T.length > MAXSIZE)
		exit(1);

	int i = 0;
	int j = 0;
	int k = 0;

	while(i < S.length && j < T.length) 
	{
		if (S.data[i] <= T.data[j])
			L.data[k++] = S.data[i++];
		else
			L.data[k++] = T.data[j++]; 
	}

	while (i < S.length)
		L.data[k++] = S.data[i++];
	
	while (j < T.length)
		L.data[k++] = T.data[j++];

	L.length = k;
	
	return L;	
}

void list_example_07() {
	SqList L = TestInitSeqData_1();
	SqList Q = TestInitSeqData_2();
	printf("顺序表第七题 \n");
	printf("原顺序表1: ");
	PrintList(L);
	printf("原顺序表2: ");
	PrintList(Q);
	printf("合并顺序表: ");
	SqList R = merge(L, Q);
	PrintList(R);
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第八题
 * 已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,...,am)和(b1,b2,...,bn)
 * 编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,...,bn)放在(a1,a2,...,am)
 * 的前面
 */

SqList ReverseArray(SqList *array) {
	SqList L;
	InitList(&L);

	for (int i = 0; i < (array + 1)->length; i++)
	{
		add(&L, (array + 1)->data[i]);
	}

	for (int j = 0; j < array->length; j++)
	{
		add(&L, array->data[j]);
	}	

	return L;
}

void list_example_08() {
	SqList L = TestInitSeqData_1();
	SqList Q = TestInitSeqData_2();	
	SqList R[2] = {L, Q};

	printf("顺序表第八题 \n");
	printf("原顺序表1: ");
	PrintList(L);
	printf("原顺序表2: ");
	PrintList(Q);
	printf("合并顺序表: ");
	SqList r = ReverseArray(R);
	PrintList(r);
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第九题
 * 线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。要求
 * 设计算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素
 * 位置交换，若找不到则将其插入表中并使表中元素仍递增有序。
 */

/** 书中使用的折半查找算法效率上是高于我这里实现的算法，书中算法更接近本题
 * 答案。我这里的时间复杂度为O(n)书中是O(logn)
 */

void FindValueIsInTable(SqList *L, ElemType e) {

	ElemType temp;
	int i;

	int x = LocateElem(*L, e); // 设查找位置为x
	
	if ( x == 0)
	{
		for (i = 0; i < L->length; i++)
		{
			if ((L->data[i] < e) && (e < L->data[i + 1]))
			{
				i += 1;
				break;
			}
		}

		ListInsert(L, i, e);

		return;
	} 

	x-=1; // 元素位置需要减1
	
	temp = L->data[x];
	L->data[x] = L->data[x + 1];
	L->data[x + 1] = temp;
}

void list_example_09() {
	SqList L = TestInitSeqData_1();
	printf("顺序表第九题 \n");
	printf("原顺序表: ");
	PrintList(L);
	printf("删除后表: ");
	FindValueIsInTable(&L, 50);
	PrintList(L);
	printf("\n");
}