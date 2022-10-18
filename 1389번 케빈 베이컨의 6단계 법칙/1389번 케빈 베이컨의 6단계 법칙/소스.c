#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int graph[105][105];
int visit[105];
int cnt;
int q[100001];
int front = 0, rear = 0;
int N, M;
int k = 0;
int answer = 1000;
int answer2=1000;
int k;
void bfs(int v)
{
	k = v;
	for (int i = 1; i <= N; i++)
	{
		visit[i] = 0;
	}
	int cnt = 0;
	q[rear++] = v;
	visit[v] = 1;
	while (front < rear)
	{
		v = q[front++];
		for (int i = 1; i <= N; i++)
		{
			if (visit[i]==0&&graph[v][i] == 1)
			{
				q[rear++] = i;
				visit[i] =visit[v]+ 1;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cnt = cnt + visit[i];
	}
	//cnt-N;
	if (answer > cnt - N)
	{
		answer = cnt - N;
		answer2 = k;
	}
	
}
int main()
{
	scanf("%d %d ", &N,&M);
	int a, b;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}
	printf("%d\n", answer2);
	return 0;
}