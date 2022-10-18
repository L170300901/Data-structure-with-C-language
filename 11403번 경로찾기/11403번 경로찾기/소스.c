#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int N;
int map[105][105];
int answer[105][105];
int visit[105];
int q[1000001];
void bfs(int x)
{
	int rear = 0, front = 0;
	for (int i = 1; i <= N; i++)
	{
		visit[i] = 0;
	}
	q[rear++] = x;//탐색 시작 
	while (front < rear)
	{
		int xp = q[front++];
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == 0 && map[xp][i] == 1)
			{
				visit[i] = 1;//들림 
				answer[x][i] = 1;
				q[rear++] = i;//큐에 저장 
			}
		}
		/*printf("###check\n");
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
			{
				printf("%d ", answer[i][j]);
			}
			printf("\n");
		}*/	
	}
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		bfs(i);
	}
	//출력 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <=N; j++)
		{
			printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
}