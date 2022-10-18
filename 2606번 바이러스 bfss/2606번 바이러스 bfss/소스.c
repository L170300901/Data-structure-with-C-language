#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int graph[1005][1005];
int visit[1005];
int cnt;
int q[100001];
int front = 0, rear = 0;
int num, N, M, V;
void bfs(int v)
{
	q[rear++] = v;
	visit[v] = 0;
	while (front < rear)
	{
		v = q[front++];
		cnt++;
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] || graph[v][i] == 0)
			{
				continue;
			}
			q[rear++] = i;
			visit[i] = 1;
		}
	}
}
int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	int a, b;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	bfs(1);
	printf("%d", cnt-2);
	return 0;
}