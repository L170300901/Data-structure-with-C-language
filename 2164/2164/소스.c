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
	Node* tail;
	Node* head;
	int numOfData;
}CList;
typedef CList List;
void ListInit(List* plist)
{
	plist->cur = NULL;
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
	free(rpos);
	(plist->numOfData)--;
	return rdata;
};
int main()
{
	List list;
	ListInit(&list);
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		Insert(&list, i);
	}
	while (list.numOfData > 1)
	{
		int temp = 0;
		FirstRemove(&list);
		temp =list.head->data;
		FirstRemove(&list);
		Insert(&list, temp);
	}
	printf("%d", list.tail->data);
}