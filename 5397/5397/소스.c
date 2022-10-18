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
int main()
{
	init();
	int i, j, len;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf(" %s", word);
		len = strlen(word);
		for (j = 0; j < len; j++)
		{
			if (word[j]== '<')
			{
				if (cur->prev == head)
				{
					continue;
				}
				cur = cur->prev;
			}
			else if (word[j] == '>')
			{
				if (cur == tail)
				{
					continue;
				}
				cur = cur->next;

			}
			else if (word[j] == '-')
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
			else 
			{
				Node* newnode = (Node*)malloc(sizeof(Node));
				newnode->prev = cur->prev;
				newnode->next = cur;
				newnode->data = word[j];
				cur->prev->next = newnode;
				cur->prev = newnode;				
			}
		}
		print();
		printf("\n");
		init();
	}
	
	return 0;
}