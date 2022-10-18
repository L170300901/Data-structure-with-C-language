#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[9][9];
int map2[9][9];
int map3[9][9];
int visit[9][9];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//»óÇÏÁÂ¿ì ÀÌµ¿  
int N, M;
int cnt,answer;
int result = 0;
int rear2 = 0;
typedef struct _q
{
	int x;  //xÁÂÇ¥ 
	int y;  //ÁÂÇ¥ 
}queue;
queue V[100001];
int rear = 0, front = 0;
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
		}
	}
}
void mapcopy()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map3[i][j] = map2[i][j];
		}
	}
}
int bfs()
{
	queue q[10001];
	for (int i = 0; i < rear2; i++)
	{
		q[i].x = V[i].x;
		q[i].y = V[i].y;
	}
	rear = rear2;
	front = 0;
	init();
	mapcopy();
	while (front < rear)
	{
		int yp = q[front].y;
		int xp = q[front].x;
		front++;
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			if (0 <= xx && xx < M && 0 <= yy && yy < N)
			{
				if (map3[yy][xx] == 0 && visit[yy][xx] == 0)
				{
					q[rear].y = yy;
					q[rear].x = xx;
					rear++;
					visit[yy][xx] = 1;
					map3[yy][xx] = 2;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			if (map3[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	/*printf("_____________________\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", map3[i][j]);
		}
		printf("\n");
	}*/

	return cnt;
}
void dfs(int cnt)
{
	if (cnt == 3)
	{
		int result = bfs();
		//printf("%d\n",result);
		if (result > answer)
		{
			answer = result;	
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map2[i][j] == 0)
			{
				map2[i][j] = 1;
				dfs(cnt+1);
				map2[i][j] = 0;
			}
		}
	}

}

int main()
{
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			map2[i][j] = map[i][j];
			if (map[i][j] == 2)
			{
				V[rear2].y = i;
				V[rear2].x = j;
				rear2++;
			}
		}
	}
	dfs(0);
	printf("%d", answer);
}