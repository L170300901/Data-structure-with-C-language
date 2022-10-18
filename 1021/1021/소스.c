#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef int Data;
typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;
typedef struct _CLL
{
	Node* cur;
	Node* cur1;
	Node* cur2;
	Node* tail;
	Node* head;
	int numOfData;
}CList;
typedef CList List;
void ListInit(List* plist)
{
	plist->cur = NULL;
	plist->cur1 = NULL;
	plist->cur2 = NULL;
	plist->tail = NULL;
	plist->head = NULL;
	plist->numOfData = 0;	
}
void Insert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	if (plist->tail == NULL)
	{
		plist->cur = newNode;
		plist->cur1 = newNode;
		plist->cur2 = newNode;
		plist->tail = newNode;
		plist->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;	
	}
	else
	{
		newNode->prev = plist->tail;
		newNode->next = plist->head;
		plist->head->prev = newNode;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
		(plist->numOfData)++;
}
int FirstRemove(List* plist)
{
	Node* rpos = plist->head;
	Data rdata = rpos->data;
	plist->head = plist->head->next;
	plist->head->prev = plist->tail;
	plist->tail->next = plist->head;
	plist->cur = plist->head;
	plist->cur1 = plist->head;
	plist->cur2 = plist->head;
	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
void left(List* plist)
{
	plist->tail = plist->head;
	plist->head = plist->tail->next;
}
void right(List* plist)
{
	plist->head = plist->tail;
	plist->tail = plist->head->prev;
}
int head(List* plist)
{
	int cnt = 0;
	while (plist->cur1->data != plist->head->data)
	{
		plist->cur1 = plist->cur1->prev;
		cnt++;
	}
	return cnt;
}
int tail(List* plist)
{
	int cnt = 0;
	while (plist->cur2->data != plist->head->data)
	{
		plist->cur2 = plist->cur2->next;
		cnt++;
	}
	return cnt;
}
int print(List* plist)
{
	plist->cur = plist->cur->next;
	return plist->cur->data;
}
int main()
{
	List list;
	ListInit(&list);
	int N, M;
	scanf(" %d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		Insert(&list, i);
	}
	int cnt = 0;
	int num;
	int res = 0;
	for (int i = 0; i < M; i++)
	{
		num = 0;
		scanf("%d", &num);
		while (num != (list.cur1->data) && num != (list.cur2->data) && num != (list.cur->data))
		{
			list.cur = list.cur->next;
			list.cur1 = list.cur1->next;
			list.cur2 = list.cur2->next;
		}
		if (tail(&list) < head(&list))
		{
			while (list.head->data != num)
			{
				right(&list);
				res++;
			}
			FirstRemove(&list);
		}
		else
		{
			while (list.head->data != num)
			{
				left(&list);
				res++;

			}
			FirstRemove(&list);
		}
	}
	printf("%d\n", res);
	
}
		