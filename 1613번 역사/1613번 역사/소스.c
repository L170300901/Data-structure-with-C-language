#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int graph[405][405];
int visit[405];
int visit2[405][405];
int cnt;
int q[1000001];
int front = 0, rear = 0;
int N, K;
void bfs(int x)
{
	q[rear++] = x;
	//√ ±‚»≠
	for (int i = 1; i <= 405; i++)
	{
		visit[i] = 0;
	}
	visit[x] = 1;

	while (front < rear)
	{
		int xx = q[front++];
		for (int i = 1; i <= N; i++)
		{
			if (graph[xx][i] == 1&&visit[i]==0)
			{
				visit2[xx][i] = 1;
				visit2[x][i] = 1;
				q[rear++] = i;
				visit[i] = 1;
			}			
		}
	}
}
int main()
{

	scanf("%d %d", &N, &K);
	int a, b;
	for (int i = 1; i <= K; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
	}
	int S;
	scanf("%d", &S);

	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}
	for (int i = 1; i <= S; i++)
	{
		int c, d;
		scanf("%d %d", &c, &d);
		if (visit2[c][d] == 1)
		{
			printf("-1\n");
		}
		else if (visit2[d][c] == 1)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}