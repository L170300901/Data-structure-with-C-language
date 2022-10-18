#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int visit[100005];
int cnt;
int q[100001];
int F, S, G, U, D;
void bfs(int x)
{
	int rear = 0, front = 0;
	q[rear++] = x;
	visit[x] = 1;
	while (front < rear)
	{
		int xp = q[front++];
		int dx[2] = { xp + U,xp - D};//위치에서 u d 밖에 못감 
		for (int i = 0; i < 2; i++)
		{
			int xx = dx[i];
			if (1 <= xx && xx <= F)//움직일수 있는 범위 1층~F층 
			{
				if (visit[xx] == 0)
				{
					visit[xx] = visit[xp] + 1;
					if (xx == G)//면접 장소에 도착 하면 
					{
						return;
					}
					q[rear++] = xx;
				}
			}
		}
	}
	printf("")
}
int main()
{
	scanf("%d %d %d %d %d", &F, &S,&G,&U,&D);
	bfs(G);
}
