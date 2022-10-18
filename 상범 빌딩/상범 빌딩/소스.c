#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int L, R, C;
char map[35][35][35];
int visit[35][35][35];
int dx[6] = { 1,-1,0,0,0,0 };//�� �� �� �� �� ��
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 }; 
int qz[1000001];//z��ǥ
int qy[1000001];//y��ǥ
int qx[10000001];//x��ǥ
int rear = 0, front = 0, rear2 = 0, front2 = 0;
int rear3 = 0, front3 = 0;
int endX, endY, endZ;
void bfs(int z,int y, int x)
{
	// ����Ʈ �ʱ�ȭ
	for (int k = 1; k <= L; k++)//z��ǥ
	{
		for (int i = 1; i <= R; i++)//y��ǥ
		{
			for (int j = 1; j <= C; j++)//x��ǥ
			{
				visit[k][i][j] = 0;
			}
		}
	}
	//ť �ʱ�ȭ
	for (int i = 0; i < 1000001; i++)
	{
		qz[i] =0 ;
		qy[i] = 0;
		qx[i] = 0;
	}
	int rear = 0, front = 0, rear2 = 0, front2 = 0;
	int rear3 = 0, front3 = 0;
	qz[rear++] = z;
	qy[rear2++] = y;
	qx[rear3++] = x;
	visit[z][y][x] = 1;
	int cnt = 0;
	
	while (front < rear)
	{
		int zp = qz[front++];
		int yp = qy[front2++];
		int xp = qx[front3++];
		/*if (yp = endY && xp == endX && zp == endZ)
		{
			printf("Escaped in %d minute(s).\n", cnt);
			break;
		}*/
		//printf("xp==%d %d %d\n", zp, yp, xp);
		for (int i = 0; i < 6; i++)
		{
			int xx = xp + dx[i];
			int yy = yp + dy[i];
			int zz = zp + dz[i];
	
			//printf("xx==%d %d %d\n", zz, yy, xx);
			
			if (1 <= xx && xx <= C && 1 <= yy && yy <=R && 1 <= zz && zz <= L)
			{
				if (visit[zz][yy][xx] == 0)
				{
					if (map[zz][yy][xx] != '#')
					{
						
						//printf("######\n");
						qz[rear++] = zz;
						qy[rear2++] = yy;
						qx[rear3++] = xx;
						visit[zz][yy][xx] = visit[zp][yp][xp]+1;
						if (yy == endY && xx == endX && zz == endZ)
						{
							printf("Escaped in %d minute(s).\n", visit[zp][yp][xp]);
							return;
						}
					}
				}
			}
		}
		
	}
	printf("Trapped!\n");
	return;
}
int main()
{
	while (1)
	{
		int z=0, y=0, x=0;
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0)//���� ���� 
		{
			break;
		}
		for (int k = 1; k <= L; k++)//z��ǥ
		{
			for (int i = 1; i <= R; i++)//y��ǥ
			{
				for (int j = 1; j <= C; j++)//x��ǥ
				{
					scanf(" %c", &map[k][i][j]);
					if (map[k][i][j] == 'S')//������ ǥ�� 
					{
						z = k;
						y = i;
						x = j;
						
					}
					if (map[k][i][j] == 'E') //Ż�ⱸ ǥ�� 
					{
						endZ = k;
						endY = i;
						endX = j;
					}
				}
			}
		}
		/*printf("---------------------------\n");
		for (int k = 1; k <= L; k++)//z��ǥ
		{
			for (int i = 1; i <= R; i++)//y��ǥ
			{
				for (int j = 1; j <= C; j++)//x��ǥ
				{
					printf("%d", visit[k][i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		*/
		bfs(z,y,x);
	}
	return 0;
	
}