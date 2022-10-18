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
	Data qarr[10000];
} CQueue;

typedef CQueue Queue;

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
	if (pos == 9999)
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
			if (QIsEmpty(&q) == TRUE)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.qarr[q.front + 1]);
				Pop(&q);
				cnt--;
			}
		}
		else if (strcmp("size", str) == 0)
		{
			printf("%d\n", cnt);
		}
		else if (strcmp("empty", str) == 0)
		{
			if (QIsEmpty(&q) == TRUE)
			{
				printf("1\n");
			}
			else
				printf("0\n");
		}
		else if (strcmp("front", str) == 0)
		{
			if (QIsEmpty(&q) == TRUE)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.qarr[q.front+1]);
			}
		}
		else if (strcmp("back", str) == 0)
		{
			if (QIsEmpty(&q) == TRUE)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", q.qarr[q.rear]);
			}
		}
	}
	return 0;
}
