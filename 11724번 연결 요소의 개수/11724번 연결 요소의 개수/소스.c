#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int N, M,u,v;
int graph[1005][1005];
int visit[1005];
int cnt;
int q[100001];
int front = 0, rear = 0;
void bfs(int v)
{
	q[rear++] = v;
	visit[v] = 1;
	while (front < rear)
	{
		v = q[front++];
		for (int i = 1; i <= N; i++)
		{
			if (visit[i]==0 && graph[v][i] == 1)
			{
				q[rear++] = i;
				visit[i] = 1;
				
			}
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u][v] = graph[v][u] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			bfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}