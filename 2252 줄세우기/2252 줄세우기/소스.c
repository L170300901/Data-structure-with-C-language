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
	Node* cur1;
	Node* cur2;
	Node* tail;
	Node* head;
}CList;
typedef CList List;
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;

	plist->cur1 = plist->head;
	plist->cur2 = plist->head;

}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

}
void cur1add(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	plist->cur1->next->prev = newNode;
	newNode->next = plist->cur1->next;

	newNode->prev = plist->cur1;
	plist->cur1->next = newNode;

	plist->cur1 = plist->head;


}
void cur2add(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	plist->cur2->next->prev = newNode;
	newNode->next = plist->cur2->next;

	newNode->prev = plist->cur2;
	plist->cur2->next = newNode;

	plist->cur2 = plist->head;


}
Data cur1Remove(List* plist)//cur1삭제
{
	Node* rpos = plist->cur1;
	Data remv = rpos->data;

	plist->cur1->prev->next = plist->cur1->next;
	plist->cur1->next->prev = plist->cur1->prev;

	plist->cur1 = plist->cur1->prev;    // cur의 위치를 재조정

}
Data cur2Remove(List* plist)//cur2삭제
{
	Node* rpos = plist->cur2;
	Data remv = rpos->data;

	plist->cur2->prev->next = plist->cur2->next;
	plist->cur2->next->prev = plist->cur2->prev;

	plist->cur2 = plist->cur2->prev;    // cur의 위치를 재조정

}
//프린트 할때 쓸꺼
int LFirst(List* plist, Data* pdata)
{
	if (plist->head->next == plist->tail)
		return 0;

	plist->cur1 = plist->head->next;
	*pdata = plist->cur1->data;
	return 1;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->cur1->next == plist->tail)
		return 0;

	plist->cur1 = plist->cur1->next;
	*pdata = plist->cur1->data;
	return 1;
}
int temp , c, d;
int N, M, a, b, temp1, temp2;
int main()
{
	List list;
	ListInit(&list);
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		LInsert(&list, i);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		if (temp1 == a || temp1 == b || temp2 == a || temp2 == b)
		{
			temp++;
			c = temp1;
			d = temp2;

		}
		while (a != 0)
		{
			list.cur1 = list.cur1->next;
			a--;
		}
		while (b != 0)
		{
			list.cur2 = list.cur2->next;
			b--;

		}
		
		
		temp1 = 0;//cur1의 데이터 저장 
		temp2 = 0;//cur2의 데이터 저장
		temp1=list.cur1->data;
		temp2 = list.cur2->data;
		
		if (temp1 > temp2)
		{
			cur1Remove(&list);
			cur1add(&list, temp2);
			cur2Remove(&list);
			cur2add(&list, temp1);

		}
		if (temp = 1)
		{
			while (c != 0)
			{
				list.cur1 = list.cur1->next;
				c--;
			}
			while (d != 0)
			{
				list.cur2 = list.cur2->next;
				d--;

			}
			temp1 = 0;//cur1의 데이터 저장 
			temp2 = 0;//cur2의 데이터 저장
			temp1 = list.cur1->data;
			temp2 = list.cur2->data;

			cur1Remove(&list);
			cur1add(&list, temp2);
			cur2Remove(&list);
			cur2add(&list, temp1);
			temp = 0;

		}
		else
		{
			list.cur1 = list.head;
			list.cur2 = list.head;
			continue;
		}
	}

	//데이터에 넣고 전체 리스트 출력하기
	int data;
	if (LFirst(&list, &data))
	{
		printf("%d", data);
		while (LNext(&list, &data))
			printf(" %d", data);

	}
	return 0;
}