#define TRUE	1
#define FALSE	0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int cnt = 0;
typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data qarr[100];
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);


void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == 100 - 1)
		return 0;
	else
		return pos + 1;
}

void Push(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->qarr[pq->rear] = data;
}

Data Pop(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->qarr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->qarr[NextPosIdx(pq->front)];
}
int main(void)
{
	Queue q;
	QueueInit(&q);
	int n, i;
	char str[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %s", str);
		if (strcmp("push", str) == 0)
		{
			int num;
			scanf("%d", &num);
			Push(&q, num);
			cnt++;
		}
		else if (strcmp("pop", str) == 0)
		{
			if (QIsEmpty(&q) == 0)
			{
				return -1;
			}
			else
			{
				printf("%d", q.front); 
				Pop(&q);
				cnt--;
			}
		}
		else if (strcmp("size", str) == 0)
		{
			printf("%d", cnt);
		}
		else if (strcmp("empty", str) == 0)
		{
			if (QIsEmpty(&q) == 0)
			{
				return 1;
			}
			else
				return 0;
		}
		else if (strcmp("front", str) == 0)
		{
			if (QIsEmpty(&q) == 0)
			{
				return -1;
			}
			else
			{
				printf("%d", q.front);
			}
		}
		else if (strcmp("back", str) == 0)
		{
			if (QIsEmpty(&q) == 0)
			{
				return -1;
			}
			/*else
			{
				//printf("%d", q.front);
			}*/
		}
	}
	return 0;
}

