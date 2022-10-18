#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _node
{
	char data;
	struct _node* next;
	struct _node* prev;
} Node;
char word[1000005];
int num;
Node* tail;
Node* head;
Node* cur;
void init()
{
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = tail;
	head->data = 'H';
	tail->prev = head;
	tail->next = tail;
	tail->data = 'T';
	cur = tail;
}
void print()
{
	Node* ins_head = head;
	while (1)
	{
		ins_head = ins_head->next;
		if (ins_head == tail)
			break;
		printf("%c", ins_head->data);
	}

}
void P(char word2)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->prev = cur->prev;
	p->next = cur;
	p->data = word2;
	cur->prev->next = p;
	cur->prev = p;
}
int main()
{
	init();
	int i,j, len;
	char edit;
	scanf(" %s",word);
	len = strlen(word);
	for (j = 0; j < len; j++)
	{
		P(word[j]);
	}
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf(" %c", &edit);
		if (edit == 'L')
		{
			if (cur->prev == head)
			{
				continue;
			}
			cur =cur->prev;
		}
		else if (edit == 'D')
		{
			if (cur == tail)
			{
				continue;
			}
			cur = cur->next; 
		}
		else if (edit == 'B')
		{
			if (cur->prev == head)
			{
				continue;
			}
			Node* del = cur->prev;
			del->prev->next = cur;
			cur->prev = del->prev;	
			free(del);
		}
		else if (edit == 'P')
		{
			char word2;
			scanf(" %c", &word2);
			P(word2);
		}
	
	}
	print();
	return 0;
}