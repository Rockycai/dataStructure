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