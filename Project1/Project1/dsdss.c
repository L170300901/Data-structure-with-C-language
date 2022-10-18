#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	char data;
	struct _node* next;
	struct _node* prev;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* cur = NULL;
void init()
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	cur = (Node*)malloc(sizeof(Node));

	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	tail->data = 't';
	head->data = 'h';
	cur = tail;
}

int n;
int main(void)
{
	char word[100000];
	char edit[600000];

	gets(word);
	scanf("%d", &n);
	int i;
	char a, ins;
	char order;
	for (i = 0; i < n; i++)
	{
		scanf("%c", &order);
		if (order == 'P')
		{
			scanf("%d", &a);

			Node* p = (Node*)malloc(sizeof(Node));
			p->prev = cur->prev;
			p->next = cur;
			p->data = ins;
			cur->prev->next = p;
			cur->prev = p;
		}
		else if (order == 'L')
		{
			if (cur->prev == head)
			{
				return;
			}
			cur = cur->prev;

		}
		else if (order == 'D')
		{
			if (cur == tail)
			{
				return;
			}
			cur = cur->next;
		}
		else if (order == 'B')
		{
			if (cur->prev == head)
			{
				return;
			}
			Node* del = cur->prev;
			del->prev->next = cur;
			cur->prev = del->prev;

		}
	}
	Node* insert_head = head;
	while (1)
	{
		insert_head = insert_head->next;
		if (insert_head == tail)
			break;
		printf("%c", insert_head->data);
	}
	return 0;
}