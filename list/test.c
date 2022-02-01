/**
 * 测试列表操作
 */

#include "list.h"

SqList TestInitData() {
	SqList L;
	L.data[0] = 100;
	L.data[1] = 71;
	L.data[2] = 18;
	L.data[3] = 61;
	L.data[4] = 53;
	L.data[5] = 88;
	L.data[6] = 71;
	L.data[7] = 64;
	L.data[8] = 67;
	L.data[9] = 59;

	L.length = 10;
	return L;
}

// 这是有序表的数据初始化
SqList TestInitSeqData() {
	SqList L;
	L.data[0] = 26;
	L.data[1] = 31;
	L.data[2] = 42;
	L.data[3] = 47;
	L.data[4] = 50;
	L.data[5] = 59;
	L.data[6] = 66;
	L.data[7] = 89;
	L.data[8] = 91;
	L.data[9] = 99;

	L.length = 10;
	return L;
}

void TestList_1() {
	SqList L;
	ElemType e; // 用于保存删除掉元素的值
	
	InitList(&L);

	printf("列表是否为空%d \n", Empty(L));

	printf("插入元素后 \n");
	// 向列表中放10元素进行测试
	for (int i = 0; i < 10; i++) {
		L.data[i] = 10 * i + 1;
		L.length++;
	}

	printf("列表是否为空%d \n", Empty(L));
	printf("列表长队为%d \n", Length(L));
	printf("寻找第3位的值 %d \n", GetElem(L, 3));

	printf("输出列表元素: \r\n");
	PrintList(L);

	printf("查找值为40所在的位置%d \n", LocateElem(L, 40));

	ListInsert(&L, 2, 101);
	PrintList(L);

	ListDelete(&L, 2, &e);
	printf("删除的值为 %d\n", e);
	PrintList(L);

	// 清空数据
	DestroyList(&L);
	PrintList(L);
}

void TestList_2() {
	SeqList L;
	ElemType e;

	InitSeqList(&L);

	printf("获取长度%d \n", SeqLength(L));

	for (int i = 0; i < 10; i++) {
		L.data[i] = 10 * i + 1;
		L.length++;
	}

	printf("列表是否为空%d \n", EmptySeq(L));
	printf("列表长队为%d \n", SeqLength(L));
	printf("寻找第3位的值 %d \n", GetSeqElem(L, 3));

	printf("输出列表元素: \r\n");
	PrintSeqList(L);
	printf("查找值为40所在的位置%d \n", LocateSeqElem(L, 40));

	ListSeqInsert(&L, 2, 101);
	PrintSeqList(L);

	ListSeqDelete(&L, 2, &e);
	printf("删除的值为 %d\n", e);
	PrintSeqList(L);

	printf("销毁空间 \n");
	DestroySeqList(&L);
}