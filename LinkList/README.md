### 例题
- 第一题:

设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点

```c
void DeleteLinkListXValues(LinkList *L, ElemType e) {
	LNode *p;
	if (*L == NULL) 
		return;

	if ((*L)->data == e) 
	{
		p = *L;
		*L = (*L)->next;
		free(p);
		DeleteLinkListXValues(&(*L), e);
	}
	else
		DeleteLinkListXValues(&(*L)->next, e);
}
```

- 第二题:

在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一。
```c
void DeleteHeadLNodeXValues(LinkList *L, ElemType e) {
	LinkList p = (*L)->next;
	LinkList s = *L;
	LinkList q;

	while (p)
	{
		if (p->data == e) 
		{
			q = p;
			p = p->next;
			s->next = p;
			free(q);
		}
		else
		{
			s = p;
			p = p->next;
		}
	}	
}
```

- 第三题

设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值

```c
void Print_R(LinkList L) {
	if (L->next != NULL) 
	{
		Print_R(L->next);
	}

	if (L != NULL)
		printf("%d ", L->data);
}
```

- 第四题

带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）

```c
void DeleteLinkListMinValue(LinkList *L) {
	LNode *pre = *L;
	LNode *p = (*L)->next;
	LNode *minpre = *L;
	LNode *min = (*L)->next;

	while (p!= NULL)
	{
		if (p->data < min->data)
		{
			min = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}

	minpre->next = min->next;
	free(min);
}
```

