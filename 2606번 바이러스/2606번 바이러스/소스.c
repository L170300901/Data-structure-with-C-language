#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int graph[105][105];
int visit[105];
int cnt;
int num, N, a, b;

void dfs(int v)
{
	cnt += 1;
	visit[v] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] || graph[v][i] == 0)
		{
			continue;
		}
		dfs(i);
	}

}
int main()
{
	scanf("%d", &N);
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	dfs(1);
	printf("%d", cnt - 1);
}