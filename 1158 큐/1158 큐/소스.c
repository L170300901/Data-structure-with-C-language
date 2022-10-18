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
	Data qarr[6000];
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
	if (pos == 6000)
		return 0;
	else
		return pos + 1;
}

void Push(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!1");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->qarr[pq->rear] = data;
}

Data Pop(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!2");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->qarr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!3");
		exit(-1);
	}

	return pq->qarr[NextPosIdx(pq->front)];
}
int main()
{
	Queue q;
	QueueInit(&q); 
	int N, K;
	int m = 0;
	scanf("%d %d", &N, &K);
	int i;
	for (i = 1; i <= N; i++)
	{
		Push(&q, i);
	}
	int cnt = 1;
	printf("<");
	while (!(QIsEmpty(&q) == TRUE))
	{
		if (K != cnt)
		{
			Pop(&q);
			cnt++;
			Push(&q, q.qarr[q.front + 1]);
		}			
		else
		{
			
			m++;
			printf("%d", q.qarr[q.front + 1]);
			Pop(&q);
			cnt = 1;
			if (m !=N )
			printf(", ");
		}
	}
	printf(">");

	return 0;
}

