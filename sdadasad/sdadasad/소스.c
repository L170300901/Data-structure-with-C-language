#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef int Data;
int num;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;
Node* tail;
Node* head;
Node* cur;

typedef struct _dbDLinkedList
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DBDLinkedList;
typedef DBDLinkedList List;
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->numOfData = 0;
}

void print()
{
	Node* ins_head = head;
	while (1)
	{
		ins_head = ins_head->next;
		if (ins_head == tail)
			break;
		printf("%d", ins_head->data);
	}

}
int main()
{
	
	List list;
	ListInit(&list);
	scanf("%d", &num);
	for (int i = num; i > 0; i--)
	{
		LInsert(&list, i);				
	}
	print();
	return 0;
}