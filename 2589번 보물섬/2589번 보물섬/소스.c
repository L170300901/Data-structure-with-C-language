#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int graph[55][55];
int visit[55][55];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� 
int q[10000001];//y��ǥ
int q2[10000001];//x��ǥ
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int cnt,cntt;
void bfs(y,x)
{
	//�ʱ�ȭ ���ֱ� 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
		}
	}
	//bfs ���� 
	q[rear++] = y;
	q2[rear2++] = x;
	visit[y][x] = 1;
	while (front < rear)
	{
		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (graph[yy][xx] == 'L' && visit[yy][xx] == 0)
				{
					q[rear++] = yy;
					q2[rear2++] = xx;
					visit[yy][xx] = visit[yp][xp] + 1;
				}
			}
		}
		//���� ���� bfs �� ���� �ִ� �Ÿ� ã������ 
	}
	/*
	printf("visit##\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("answer##\n");
	*/
	cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] != 0)
			{
				if (cnt < visit[i][j])
				{
					cnt = visit[i][j];
				}
			}
		}
	}
	
}
int main()
{
	scanf("%d %d", &N, &M);//���� ���� �Է� ���� 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &graph[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (graph[i][j] == 'L')
			{
				bfs(i, j);
				if (cnt > cntt)
				{
					cntt = cnt;
				}

			}
		}
	}
	printf("%d", cntt-1);
}