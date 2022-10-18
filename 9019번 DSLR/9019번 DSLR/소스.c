#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int visit[10005];
int N;
int cnt;
typedef struct _q 
{
	int a;
	char b[10005];
}queue;
void bfs(int s, int e)
{
	queue q[100005];
	int rear = 0, front = 0;

	q[rear].a= s;
	q[rear].b = ' ';
	printf("111temp===%c\n", q[rear].b);
	rear++;
	visit[s] = 1;

	while (front < rear)
	{
		int xx = q[front].a;
		char temp= q[front].b;
		printf("temp===%c\n", temp);
		front++;

		if (xx == e)
		{
			return; 
		}
		////////////////////////////////////////////D
		int d;
		d = (2 * xx);
		if (d > 9999)
		{
			d = (2 * xx) % 10000;
		}
		if (visit[d] == 0) 
		{
			q[rear].a = d;
			q[rear].b =strcat(temp,'D');
			rear++;

			visit[d] = 1;
		}

		////////////////////////////////////////////S
		if (xx == 0) 
		{
			if (visit[9999] == 0) 
			{;
				q[rear].a= 9999;
				q[rear].b = strcat(temp, 'S');
				rear++;

				visit[9999] = 1;
			}
		}
		else 
		{
			if (visit[xx - 1] == 0)
			{
				q[rear].a= xx-1;
				q[rear].b = strcat(temp, 'S');
				rear++;

				visit[xx - 1] = 1;
			}
		}

		////////////////////////////////////////////L
		int first;
		first= xx / 1000;
		int remain;
		remain = xx % 1000;
		int complete;
		complete= remain * 10 + first;
		if (visit[complete] == 0) 
		{
			q[rear].a = complete;
			q[rear].b = strcat(temp, 'L');
			//strcpy(q[rear].b,(strcat(temp,"L"));
			rear++;

			visit[complete] = 1;
		}

		////////////////////////////////////////////R
		first = xx / 10; 
		remain = xx % 10;
		complete = remain * 1000 + first;

		if (visit[complete] == 0) 
		{
			q[rear].a = complete;
			q[rear].b = strcat(temp, 'R');
			rear++;

			visit[complete] = 1;
		}	
	}
}
//초기화
void init() 
{
	for (int i = 0; i < 10005; i++)
	{
		visit[i] = 0;
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		//visit 매번 초기화 해야됨 

		init();
		int S, E;
		scanf("%d %d", &S, &E);
		bfs(S, E);
		printf("\n");
	}

}