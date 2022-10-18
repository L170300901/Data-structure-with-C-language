#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int map[30][30];
int visit[30][30];
int cnt, cntt;//단지수 , 아파트수
int dx[4] ={ 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };//상하좌우 이동 
int q[100001];
int q2[100001];
int answer[30];
int m;
void bubble(int arr[], int n)
{
	int i, k, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (k = 1; k < n - 1-i; k++)
		{
			if (arr[k] > arr[k + 1]) 
			{
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}
void bfs (int x,int y)
{
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;
	q[rear++] = x;//x좌표 넣을거 
	q2[rear2++] = y;
	visit[x][y] = 1;
	cntt = 0;
	while (front<rear)
	{
		x = q[front++];
		y = q2[front2++];
		cntt++;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (visit[xx][yy] == 0 && map[xx][yy] == 1)
			{
				q[rear++] = xx;
				q2[rear2++] = yy;
				visit[xx][yy] = 1;
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d",& N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0 && map[i][j] == 1)
			{
				//visit[i][j] = 1;
				cnt++;
				bfs(i, j);
				answer[m] = cntt;
				m++;
			}
		}
	}
	bubble(answer, m);
	printf("%d\n",cnt);
	for (int i = 0; i < m; i++)
	{
		printf("%d\n",answer[i]);
	}

}