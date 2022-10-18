#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
char map[4][4];
visit
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� 
int q[10000001];//y��ǥ
int q2[10000001];//x��ǥ
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int cnt,cntt;
char answer[4][4] =
{
	"123",
	"456",
	"789"
};
void dfs (int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (0 <= xx && xx < M && 0 <= yy && yy < N)
		{
			if (visit[yy][xx] != 1 && map[yy][xx] > 0)
			{
				dfs(yy, xx);
			}
		}

	}
	

}
void bfs()
{
	while (front < rear)
	{

		for (int i = 0; i < 3; i++) //������ ��  ������ ���� �Ҳ��� 
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j] == answer[i][j])
				{
					cntt++;
				}
			}
		}
		if (cntt == 9)
		{
			printf("%d", cnt);
			return;
		}

		cnt++; //ī���� �ø� 

		int yp = q[front++];
		int xp = q2[front2++];
		for (int i = 0; i < 4; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			//printf("xx=%d yy=%d\n", xx, yy);
			if (0 <= xx && xx < 3 && 0 <= yy && yy < 3)
			{
				map[yp][xp] = map[yy][xx];
				map[yy][xx] = '9';
				q[rear++] = yy;
				q2[rear2++] = xx;
				
			}
		}
		printf("-----------------------\n");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%c ", map[i][j]);
			}
			printf("\n");
		}
		
	}
}
int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '0') //0�� 9�� �ٲ��� 
			{
				/*map[i][j] = '9';
				q[rear++] = i;
				q2[rear2++] = j;*/
				dfs(i, j);
				
			}
		}
	}
	/*for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}*/
	bfs();
	
}