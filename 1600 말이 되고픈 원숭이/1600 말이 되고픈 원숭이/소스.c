#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _q {
	int a;
	int b;
	int c;
	int d;
}queue;

queue q[10000001];

int k,N,M;
int map[205][205];
int visit[205][205][35];
int rear, front;
//������
int ddy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int ddx[8] = { -1,-2,-2,-1,1,2,2,1 }; //��ó�� ������ 
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//������ ������ 
void bfs()
{
	q[rear].a = 0;
	q[rear].b = 0;
	q[rear].c = k;
	q[rear].d = 0;
	rear++;

	visit[0][0][k] = 1; //������
	while (front < rear)
	{
		//printf("###");
		int yp = q[front].a;
		int xp = q[front].b;
		int kk = q[front].c;
		int cnt = q[front].d;
		front++;
		//printf("yp==%d xp==%d kk==%d cnt==%d\n", yp, xp, kk, cnt);
		//�����̰� ������ ���� �ϸ� ���� 
		if (yp == M - 1 && xp == N - 1)  
		{
			printf("%d", cnt);
			return;
		}

		if (kk>0)//��ó�� �����̱�
		{
			for (int i = 0; i < 8; i++)
			{
				int xx = xp + ddx[i];
				int yy = yp + ddy[i];
				if (0 <= xx && xx < N && 0 <= yy && yy < M)
				{
					if (map[yy][xx] == 0 && visit[yy][xx][kk-1] == 0)
					{
						//printf("xp=%d yp=%d i=%d ##\n",xp,yp,i);
						//printf("xx=%d yy=%d map=%d\n", yy, xx, map[yy][xx]);
						visit[yy][xx][kk-1] = 1;
						q[rear].a = yy;
						q[rear].b = xx;
						q[rear].c = kk-1;
						q[rear].d = cnt+1;
						rear++;
					}
				}

			}
		}
		//������ ó�� �����̱� 
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < N && 0 <= yy && yy < M)
			{
				if (map[yy][xx] == 0 && visit[yy][xx][kk] == 0)
				{
					visit[yy][xx][kk] = 1;
					q[rear].a = yy;
					q[rear].b = xx;
					q[rear].c = kk;
					q[rear].d = cnt+1;
					rear++;
				}
			}
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	scanf("%d", &k);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	bfs();
}