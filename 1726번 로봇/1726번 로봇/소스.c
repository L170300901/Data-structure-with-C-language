#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int map[105][105];
int visit[105][105][5];
int dy[5] = { 0,0,0,1,-1 };
int dx[5] = { 0,1,-1,0,0 };
int startA, startB, startC, endA, endB, endC;

int cnt;
typedef struct _q 
{
	int a;//y좌표
	int b;// x 좌표
	int c;//방향 
	int d;//cnt 
}queue;

queue q[1000005];
int rear = 0, front = 0;
int cntt;
void bfs(int y,int x,int z)
{
	q[rear].a = y;
	q[rear].b = x;
	q[rear].c = z;
	q[rear].d = 0;
	rear++;
	//visit[y][x][z] =1;

	while (front < rear)
	{
		//printf("###############\n");
		int yp = q[front].a;
		int xp = q[front].b;
		int zp = q[front].c;
		int cnt = q[front].d;
		front++;
		//printf("yp== %d xp====%d zp====%d \n", yp, xp, zp);
		//printf("cnt=%d\n", cnt);
		//움직여서 도착점에 도착지 종료
		if (yp == endA && xp == endB && zp == endC)
		{
			printf("%d\n", cnt);
			return ;
		}
		//앞으로 움직이기 1~3칸 
		for (int i = 1; i <= 3; i++)
		{
			int yyy = yp + dy[zp] * i;
			int xxx = xp + dx[zp] * i;
			/*
			if (1 <= xxx && xxx <= M && 1 <= yyy && yyy <= N)
			{
				if (map[yyy][xxx] == 0 && visit[yyy][xxx][zp] == 0)
				{
					printf("yyy=%d xxx=%d", yyy, xxx);
					visit[yyy][xxx][zp] = 1;
					q[rear].a = yyy;
					q[rear].b = xxx;
					q[rear].c = zp;
					q[rear].d = cnt + 1;
					rear++;
				}
			}
			*/
			if (yyy <= 0 || yyy > N || xxx <= 0 || xxx > M)
			{
				break;
			}
			// 만약 2칸앞에 벽이면 앞으로 이동하는건 불가능하다 그니까 이떄 break 해야댐 
			if (map[yyy][xxx] == 1)
			{
				break;
			}

			if (visit[yyy][xxx][z])
			{
				continue;
			}
			visit[yyy][xxx][zp] = 1;
			q[rear].a = yyy;
			q[rear].b = xxx;
			q[rear].c = zp;
			q[rear].d = cnt + 1;
			rear++;

		}
		//방향 전환
		for (int j= 1; j <= 4; j++)
		{
			//printf("j==%d zp==%d cntt=%d\n",j,zp,cntt);
			if (j == zp)
			{
				continue;
			}		
			if (visit[yp][xp][j]==0)
			{
				cntt = 1;
				if (zp == 1)
				{
					if (j == 2)
					{
						cntt++;
					}
				}
				else if (zp == 2)
				{
					if (j == 1)
					{
						cntt++;
					}
				}
				else if (zp == 3)
				{
					if (j == 4)
					{
						//printf("1###\n");
						cntt++;
					}
				}
				else
				{
					if (j == 3)
					{
						//printf("2###\n");
						cntt++;
					}
				}
				visit[yp][xp][j] = 1;
				q[rear].a = yp;
				q[rear].b = xp;
				q[rear].c = j;
				q[rear].d = cnt + cntt;
				rear++;
			}
			
		}		
	}
}
int main()
{

	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d", &startA, &startB, &startC);
	/*map[startA][startB] = 4;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/
	scanf("%d %d %d", &endA, &endB, &endC);
	bfs(startA,startB,startC);
}