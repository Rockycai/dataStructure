/**
 * 测试列表操作
 */

#include "list.h"

void TestList() {
	SqList L;
	
	// 向列表中放MAXSIZE元素进行测试
	for (int i = 0; i < MAXSIZE; i++) {
		L.data[i] = 10 * i;
		L.length++;
	}
	printf("列表长队为%d \n", Length(L));

	printf("寻找第3位的值 %d \n", GetElem(L, 3));

	printf("输出列表元素: \r\n");
	PrintList(L);

	printf("查找值为40所在的位置%d \n", LocateElem(L, 40));

}