## 线性表的定义和基本操作
具有相同数据类型的n(n>=0)个数据元素的有限序列，当n=0时线性表是一个空表。

```
L = (a1,a2,...an)
```

### 特点
- 表中元素的个数有限
- 表中元素有逻辑是的顺序性，表中元素有其先后次序
- 表中元素都是数据元素，每个元素都是单个元素
- 表中元素的数据类型都相同，每个元素占有相同大小存储空间

#### 基本操作
- InitList(*L): 创建一个空表
- Length(L): 求表长
- LocateElem(L, e): 按值查找
- GetElem(L, i): 按位查找
- ListInsert(*L, i, e): 插入操作
- ListDelete(*L, i, *e): 删除操作
- PrintList(L): 输出操作
- Empty(L): 是否为空
- DestroyList(*L): 销毁操作

### 顺序表特点
- 逻辑顺序与无力顺序相同
- 设启始位置为LOC(A), sizeof(ElemType)是每个存储元素占用的空间

```
a[0] = LOC(A)
a[1] = LOC(A) + sizeof(ElemType)
a[2] = LOC(A) + 2 * sizeof(ElemType)
```

注意： 下标位置, 线性表中元素从1开始，数组中是从0开始

线性表顺序存储定义
```c
typedef struct SqList {
	ElemType data[MAXSIZE];
	int length;
} SqList;
```

线性表空间被占用满时，在添加元素会发生错误

#### 线性表动态存储
动态存储定义
```c
typedef struct SeqList {
	ElemType *data;
	int length;
} SeqList;
```
动态分配语句

`L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize)`

### 顺序表总结
- 随机访问, 通过首地址和元素号可在O(1)内找到指定元素
- 存储密度高，每个节点只存储数据元素
- 元素逻辑物理上相邻，插入和删除需要移动大量元素

## 心情
我们要飞到那遥远地方 看一看
这世界并非那么凄凉

### 例题
- 第一题:

从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值空出的位置由最后一个元素填补，若顺序表为空则显示出错误信息并退出运行

```c
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
```

- 第二题:

设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)
```c
void Reverse(SqList *L) {
	ElemType temp;

	for (int i = 0; i < L->length/2; i++) 
	{
		temp = L->data[i];
		L->data[i] = L->data[L->length - i - 1];
		L->data[L->length - i - 1] = temp;
	}
}
```

- 第三题

对长度为n的顺序表L，编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素。

```c
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
```

- 第四题

从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素，如果s或t不合理或顺序表为空，则显示出错误信息并退出运行。

```c
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
```

- 第五题

从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，如果s或t不合理或顺序表为空，则显示出错信息并退出

/**
 * 这里解题思路和书本答案差距较大。这里我使用一个临时空间用来存储符合元素的
 * 值，符合要求就把元素插入数组尾部，在遍历临时数组和顺序表中的值做对比合适
 * 就删除，我这里因为用的都是已经实现的算法，里面循环比较多，算法时间复杂度
 * 和空间复杂度都高于书中给的答案对效率有要求的话建议书中答案来实现。 
 */

```c
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
```
```c
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
```

- 第六题
从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。

```c
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
```

- 第七题

将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表

```c
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
```

- 第八题

已知在一维数组A[m+n]中依次存放两个线性表(a1,a2,...,am)和(b1,b2,...,bn)编写一个函数，将数组中两个顺序表的位置互换，即将(b1,b2,...,bn)放在(a1,a2,...,am)的前面

```c
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
```

- 第九题

线性表(a1,a2,a3,...,an)中的元素递增有序且按顺序存储于计算机内。要求设算法，完成用最少时间在表中查找数值为x的元素，若找到则将其与后继元素位置交换，若找不到则将其插入表中并使表中元素仍递增有序。

书中使用的折半查找算法效率上是高于我这里实现的算法，书中算法更接近本题答案。我这里的时间复杂度为O(n)书中是O(logn)

```c
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
```