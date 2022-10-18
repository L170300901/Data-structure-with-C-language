#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int map[105][105];
int visit[105][105][4];
int dx[5] = { 0.1,-1,0,0 };
int dy[5] = { 0,0,0,-1,1 };//µ¿¼­³²ºÏ
int startA, startB, startC, endA, endB, endC;

int cnt;
typedef struct _q
{
	int a;//yÁÂÇ¥
	int b;// x ÁÂÇ¥
	int c;//¹æÇâ 
	int d;//cnt 
}queue;

queue q[1000001];
int rear = 0, front = 0;

void bfs(int y, int x, int z)
{
	q[rear].a = y;
	q[rear].b = x;
	q[rear].c = z;
	q[rear].d = 0;
	rear++;
	visit[y][x][z] = 1;


	while (front < rear)
	{
		int yp = q[front].a;
		int xp = q[front].b;
		int zp = q[front].c;
		int cnt = q[front].d;
		front++;

		//¿òÁ÷¿©¼­ µµÂøÁ¡¿¡ µµÂøÁö Á¾·á
		if (yp == endA && xp == endB && zp == endC)
		{
			return;
		}
		for (int j = 1; j <= 4; j++)
		{


		}
	



	}
}
int main()
{

	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d", &startA, &startB, &startC);
	scanf("%d %d %d", &endA, &endB, &endC);
	bfs(startA, startB, startC);
}