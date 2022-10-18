#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int n, a, b,m,c,d;
int graph[105][105];
int visit[105];
int cnt;
int q[100001];
int front = 0, rear = 0;
void bfs(int v,int u)
{
	q[rear++] = v;
	visit[v] = 1;
	while (front < rear)
	{
		v = q[front++];
		
		if (v == u)
		{
			break;
		}
		for (int i = 1; i <=n; i++)
		{
			if (visit[i] == 0 && graph[v][i] == 1)
			{
				q[rear++] = i;
				visit[i] =visit[v]+1;
			}
		}
		/*printf("###\n");
		for (int i = 1; i <= n; i++)
		{
			printf("###%d\n", visit[i]);
		}*/
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
		graph[c][d]=graph[d][c] = 1;
	}
	bfs(a,b);
	printf("%d", visit[b]-1);
}
