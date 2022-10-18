#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int n, a, b, m, c, d;
int graph[105][105];
int visit[105];
int cnt;
void dfs(int v, int u)
{
	cnt++;
	visit[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i]==0&& graph[v][i] == 1)
		{
			printf("###i=%d\n", i);
			printf("###u=%d\n", u);
			printf("cnt=%d\n", cnt);
			if (i == u)
			{
				printf("####\n");
				return;
			}
			dfs(i, u);
		}
	}

}
int main()
{
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &c, &d);
		graph[c][d] = graph[d][c] = 1;
	}
	dfs(a, b);
	if (cnt == 0)
	{
		printf("-1");
		return 0;
	}
	printf("%d", cnt);
}