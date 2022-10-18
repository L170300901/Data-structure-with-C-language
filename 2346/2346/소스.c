#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef int Data;
int cnt = 1;
typedef struct _node
{
	int idx;
	Data data;
	struct _node* next;
	struct _node* prev;
} Node;
typedef struct _linlist
{
	Node* head;
	Node* tail;
	Node* cur;
	Node* cur1;
	int numofdata; //풍선 번호 

}Linklist;
typedef Linklist List;
void ListInit(List* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->cur = NULL;
	plist->cur1 = NULL;
	plist->numofdata = NULL;
}
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->idx = cnt++;
	newNode->data=data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (plist->head==NULL)
	{
		plist->head = newNode;
		plist->tail = newNode;
		plist->cur = newNode;
		plist->cur1 = newNode;

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
	//(plist->numofdata)++;

}
void FirstRemove(List* plist)
{
	Node* rpos = plist->head;
	printf("%d ", rpos->idx);
	Data rdata = rpos->data;

	plist->head=plist ->head->next;
	plist->cur = plist->head;
	plist->cur1 =plist->head;

	plist->head->prev = plist->tail;
	plist->tail->next = plist->head;

	free(rpos);
	(plist->numofdata)--;
	
}
void RemoveCur1(List* plist)
{
	Node* rpos = plist->cur1;
	Data rdata = rpos->data;
	plist->cur1->prev->next = plist->cur1->next;
	plist->cur1->next->prev = plist->cur1->prev;

	printf("%d ", rpos->idx);
	plist->cur = plist->cur->next;
	plist->cur1 = plist->cur;
	free(rpos);
	(plist->numofdata)--;
}
int main()
{
	List list;	
	ListInit(&list);
	int N, num;
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
	{		
		scanf("%d", &num);
		LInsert(&list, num);
		list.numofdata = i;	
	}

	int temp = 0;
	temp = list.head->data;
	FirstRemove(&list);//첫번째 노드 삭제 
	//printf("head=%d\n", list.head->data);
	//printf("tail=%d\n", list.tail->data);
	//printf("cur=%d\n", list.cur->data);
	//printf("$$\n");
	if (temp > 0)
	{
		temp = temp - 1;
		while (temp != 0)
		{
			list.cur = list.cur->next;
			list.cur1 = list.cur1->next;
			temp--;
		}
	}
	else
	{
		while (temp != 0)
		{
			list.cur = list .cur->prev;
			temp++;

		}
	}


	//첫번째 노드 삭제 끝 cur 위치 바꾸기 완료
	while (list.numofdata != 0)
	{
		int temp2 = 0;
		temp2=list.cur->data;
		if (list.cur->data == list.tail->data)
		{
			list.tail=list.tail->prev;
		}
		if (list.cur->data == list.head->data)
		{
			list.head = list.head->next;
		}
		//printf("head=%d\n", list.head->data);
		//printf("tail=%d\n", list.tail->data);
		//printf("cur=%d\n", list.cur->data);
		//printf("cur1=%d\n", list.cur->data);
		//printf("$$\n");
		list.cur1 = list.cur;
		RemoveCur1(&list);
		if (temp2 > 0)
		{
			temp2 = temp2 - 1;
			while (temp2 != 0)
			{
				list.cur = list.cur->next;
				temp2--;
			}
						
		}
		else
		{
			while (temp2 != 0)
			{
				list.cur = list.cur->prev;
				temp2++;
			}
		}
	}
	//printf("%d", list.numofdata);
	return 0;	
}