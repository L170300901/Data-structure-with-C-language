#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char map[15][10];
int visit[15][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };//�����¿� �̵� '
int cnt;
int del;
char q[10000001];//y��ǥ
int rear = 0, front = 0, rear2 = 0, front2 = 0;
void boom(int y, int x, char color)
{
	for (int i = 0; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (0 <= xx && xx < 6 && 0 <= yy && yy < 12)
		{
			if (visit[yy][xx] == 0 && color == map[yy][xx])//ó�� ���� ���̰� ���°��� �����ϋ� 
			{
				visit[yy][xx] = 1;
				map[yy][xx] = '.';
				boom(yy, xx, color);
			}
		}
	}
}
void dfs(int y, int x)
{
	if (cnt >= 4)//���� �÷��� 4���̻� �پ� ������ �Ͷ߸����� 
	{
		del = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (0 <= xx && xx < 6 && 0 <= yy && yy < 12)
		{
			if (visit[yy][xx] ==0 && map[yy][xx]==map[y][x] )//ó�� ���� ���̰� ���°��� �����ϋ� 
			{
				visit[yy][xx] = 1;
				cnt++;
				dfs(yy, xx);
				visit[yy][xx] = 0;
				/*if (color == map[yy][xx]) //�� �÷��� ������ �ϴ� ���� �÷��� ������
				{
					visit[yy][xx] = 1;
					cnt++;
					dfs(yy, xx,color);
					visit[yy][xx] = 0;

				}*/
			}
		}
	}
}
void arr() //�ѿ� �������� �ִ°� �����ٲ��� 
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 11; i >=0; i--)
		{
			visit[i][j] = 0;
			if (map[i][j] != '.')
			{
				q[rear++] = map[i][j];
				map[i][j] = '.';
			}
		}
		for (int i = 11; i >= 0; i--)
		{
			if (front < rear)
			{
				char a = q[front++];
				map[i][j] = a;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			scanf(" %c", &map[i][j]);
		}
	}
	int answer = 0;//���� ���� �������� ������ ��� �Ҳ��� 
	//�Է� �ޱ� �Ϸ�
	while (1)
	{
		del = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.' && visit[i][j] == 0)//�����϶� 
				{
					cnt = 1;
					visit[i][j] = 1;
					dfs(i, j); //dfs�� ���� �̿��� ���� 4�� �̻��� �ִ��� Ȯ�� 
					if (cnt >= 4)//cnt�� 4�̻��� �Ǹ� cnt �ٽ� 0���� ���鲨�� 
					{
						//del += cnt;
						cnt = 0;
						boom(i, j, map[i][j]);
						map[i][j] = '.';

					}
				}
				cnt = 0;

			}
		}
		arr();
		if (del ==1)
		{
			answer++;
		}
		if (del == 0)
		{
			
			break;
		}	
	}
	printf("%d", answer);
	return 0;
}