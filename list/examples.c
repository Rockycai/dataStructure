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

// ----------------------------------------------------------------
/**
 * 第十题（2010统考真题）
 * 设将n(n > 1)个整数存放到一维数组R中。设计一个在时间和空间两个方面都尽
 * 可能高效的算法。将R中保存的序列循环左移p(0 < p < n)个位置，即将R中的
 * 数据由(X0,X1,...,Xn-1)变换为(Xp,Xp+1,...,Xn-1,X0,X1,...,Xp-1)
 */

void ReverseMove(int R[], int from, int to) {
	int temp;

	for (int i = 0; i < (to - from + 1)/2; i++) 
	{
		temp = R[from + i];
		R[from + i] = R[to - i];
		R[to - i] = temp;
	}
}

void Converse(int R[], int n, int p) {
	ReverseMove(R, 0, p-1);
	ReverseMove(R, p, n-1);
	ReverseMove(R, 0, n-1);
}

void list_example_10() {
	int array[5] = {1, 2, 3, 4, 5};
	printf("顺序表第十题 \n");
	printf("原顺序表: ");
	for (int i = 0; i < 5; i++) 
		printf("%d ", array[i]);
	printf("\n");

	Converse(array, 5, 3);
	printf("删除后表: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", array[i]);
	printf("\n\n");
}

// ----------------------------------------------------------------
/**
 * 第十一题（2011统考真题）
 * 一个长度为L(L >= 1)的升序序列S,处在第[L/2]个位置的数称为S的中位数。
 * 例如，若序列S1=(11,13,15,17,19),则S1的中位数是15，两个序列的中位
 * 数是包含它们所有元素的升序序列的中位数。例如，若S2=(2,4,6,8,20),则
 * S1和S2的中位数是11。现在有两个等长升序序列A和B，设计一个在时间和空间
 * 两个方面都尽可能高的算法，找出两个序列A和B的中位数。
 */

int M_Search(int A[], int B[], int n)
{
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n -1, m2;
	while (s1 != d1 || s2 != d2)
	{
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2])
		{
			if ((s1 + d1) % 2 == 0)
			{
				s1 = m1;
				d2 = m2;
			}
			else 
			{
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		else 
		{
			if ((s2 + d2) % 2 == 0)
			{
				d1 = m1;
				s2 = m2;
			}
			else
			{
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return A[s1] < B[s2] ? A[s1]:B[s2];
}

ElemType SearchMiddleValue(SqList L, SqList Q) {
	ElemType middle;
	SqList R = merge(L, Q);
	middle = ((L.length - 1) + (Q.length - 1)) / 2;
	return  R.data[middle];
}

// 书中答案在效率上明显高于自己写的答案，建议熟读书中答案
void list_example_11() {
	SqList L;
	SqList Q;

	InitList(&L);
	L.data[0] = 11;
	L.data[1] = 13;
	L.data[2] = 15;
	L.data[3] = 17;
	L.data[4] = 19;
	L.length = 5;

	InitList(&Q);
	Q.data[0] = 2;
	Q.data[1] = 4;
	Q.data[2] = 6;
	Q.data[3] = 8;
	Q.data[4] = 20;
	Q.length = 5;

	printf("顺序表第十题 \n");
	printf("原顺序表1: ");
	PrintList(L);
	printf("原顺序表2: ");
	PrintList(Q);
	printf("非书中中位数: %d \n", SearchMiddleValue(L, Q));

	// 书中答案	
	int A[] = {11,13,15,17,19};
	int B[] = {2,4,6,8,20};
	printf("书中答案中位数 %d\n", M_Search(A, B, 5));
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第十二题（2013统考真题）
 * 已知一个整数序列A = ( a0，a1，...an-1),其中0≤ai＜n（0≤i＜n）。若
 * 存在ap1=ap2=···=apm=x，且m>n/2（0＜pk＜n，1≤k≤m），则称x为A的主
 * 元素。例如A=（0,5,5,3,5,7,5,5），则5为主元素；又如A = ( 0,5,5,3,5,1,5 ,7 )，
 * 则A中没有主元素。 假设A中的几个元素保存在一个一维数组中，请设计一个尽可能高效的算法，
 * 找出A的主元素。若存在主元素，则输出该元素；否则输出-1
 */

int Majority(int *A, int n) {
	int i, c, count = 1;
	c = *A;

	for (int i = 1; i < n; i++)
	{
		if (A[i] == c)
			count++;
		else 
		{
			if (count > 0)
			{
				count--;
			}
			else
			{
				c = A[i];
				count = 1;
			}
		}
	}
	if (count > 0)
		for (i = count = 0; i < n; i++)
			if (A[i] == c)
				count++;

	if (count > n/2)
		return c;
	else
		return -1;
}

void list_example_12() {
	int A[8] = {0, 5, 5, 3, 5, 7, 5, 5};
	int B[8] = {0, 5, 5, 3, 5, 1, 5, 7};

	printf("顺序表第十二题 \n");
	printf("原顺序表A: ");
	for (int i = 0; i < sizeof(A)/sizeof(int); i++) 
		printf("%d ", A[i]);
	printf("\n");
	printf("原顺序表B: ");
	for (int i = 0; i < sizeof(B)/sizeof(int); i++) 
		printf("%d ", B[i]);
	printf("\n");
	printf("A主元素为: %d\n", Majority(A, sizeof(A)/sizeof(int)));
	printf("B主元素为: %d\n", Majority(B, sizeof(B)/sizeof(int)));
	printf("\n");
}

// ----------------------------------------------------------------
/**
 * 第十三题（2018统考真题）
 * 给定一个含n（n>=1）个整数的数组，请设计一个在时间上尽可能高效的算法，找
 * 出数组中未出现的最小正整数。例如，数组{-5,3,2,3}中未出现的最小正整数是
 * 1；数组{1,2,3}中未出现的最小正整数是4。
 */

int findMissMin(int A[], int n)
{
	int i, *B;
	B = (int *)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n);
	for (i = 0; i < n; i++)
		if (A[i] > 0 && A[i] <= n)
			B[A[i] - 1] = 1;
	
	for (i = 0; i < n; i++)
		if (B[i] == 0)
			break;
	
	return i + 1;
}

void list_example_13() {
	int A[4] = {-5, 3, 2, 3}; 
	int B[3] = {1, 2, 3};
	printf("顺序表第十三题 \n");
	printf("原顺序表A: ");
	for (int i = 0; i < sizeof(A)/ sizeof(int); i++)
		printf("%d ", A[i]);
	printf("\n");
	printf("原顺序表B: ");
	for (int i = 0; i < sizeof(B)/ sizeof(int); i++)
		printf("%d ", B[i]);
	printf("\n");

	int resultA = findMissMin(A, 3);
	int resultB = findMissMin(B, 3);
	printf("数组A最小正整数 %d\n", resultA);
	printf("数组B最小正整数 %d\n", resultB);
	printf("\n");
}