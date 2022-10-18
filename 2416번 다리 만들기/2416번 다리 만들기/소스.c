#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _q 
{
	int x;  //x좌표 
	int y;  //좌표 
}queue;
queue q[10000001];
queue q2[10000001];
int graph[105][105];
int visit[105][105];
int visitnew[105][105];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//상하좌우 이동 

int N;
int rear = 0, front = 0;
int rear2 = 0, front2 = 0;
int cnt,temp, answer=99999;
void bfs(int y,int x)
{
	q[rear].y = y;//y좌표 넣을거
	q[rear].x = x;//x좌표 넣기
	rear++;

	visit[y][x] = cnt;
	visitnew[y][x] = cnt;
	//육지 간의 구분을 해줄꺼임 
	while (front < rear)
	{
		int yp = q[front].y;
		int xp = q[front].x;
		front++;

		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (graph[yy][xx] == 1 && visit[yy][xx] == 0)
				{
					q[rear].y = yy;
					q[rear].x = xx;
					rear++;

					visit[yy][xx] =cnt;
					visitnew[yy][xx] = cnt;
				}
			}
		}
	}
	/*
	printf("-------------\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", visitnew[i][j]);
		}
		printf("\n");
	}
	*/
}
void minbfs() //섬과 섬과의 최소 거리 찾기 
{
	while (front2 < rear2)
	{
		int yp = q2[front2].y;
		int xp = q2[front2].x;
		front2++;
		//printf("yp=%d xp=%d\n", yp, xp);
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("yy=%d xx=%d\n", yy, xx);
			if ((graph[yy][xx] == 1 && visit[yy][xx] != cnt))
			{
				//printf("temp====%d\n", temp);
				temp = visit[yp][xp];
				if (answer > temp)
				{
					//printf("answer=====%d\n", answer);
					answer = temp;
				}
				/*printf("-------------\n");
				or (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						printf("%d ", visit[i][j]);
					}
					printf("\n");
				}
				return;*/
			}
			if (0 <= xx && xx < N && 0 <= yy && yy < N)
			{
				if (graph[yy][xx] == 0 && visit[yy][xx] == 0)
				{
					q2[rear2].y = yy;
					q2[rear2].x = xx;
					rear2++;
					visit[yy][xx] =visit[yp][xp]+1;
				}
			}
		}
	
	}
	
}
int main()
{
	cnt = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j] == 1 && visit[i][j] == 0)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	//현제 cnt =3 
	//섬의 개수많음 반복문 실행 
	cnt--;
	//printf("cnt==%d\n", cnt);
	while (cnt != 0) 
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				visit[i][j] = visitnew[i][j];
			}
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == 1 && visit[i][j] == cnt) 
				{
					//printf("i==%d j==%d\n", i, j);
					for (int ii = 0; ii < 4; ii++)
					{
						int xxx = j + dx[ii];
						int yyy = i + dy[ii];
						if (0 <= xxx && xxx < N && 0 <= yyy && yyy < N)
						{
							if (graph[yyy][xxx] == 0 && visit[yyy][xxx] == 0)  
							{
								//printf("yyy==%d xxx==%d\n", yyy, xxx);
								q2[rear2].y = yyy;
								q2[rear2].x = xxx;
								rear2++;
								visit[yyy][xxx] = 1;
							}
						}
					}

				}
			}
		}
		minbfs();
		cnt--;
	}
	printf("%d\n", answer);
	
}