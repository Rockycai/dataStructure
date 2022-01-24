/**
 * 测试列表操作
 */

#include "list.h"

void TestList() {
	SqList L;
	ElemType e; // 用于保存删除掉元素的值
	
	InitList(&L);

	printf("列表是否为空%d \n", Empty(L));

	printf("插入元素后 \n");
	// 向列表中放10元素进行测试
	for (int i = 0; i < 10; i++) {
		L.data[i] = 10 * i;
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