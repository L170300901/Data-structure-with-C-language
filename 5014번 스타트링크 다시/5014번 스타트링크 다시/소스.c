#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int visit[1000005];
int cnt;
int q[100000005];
int F, S, G, U, D;
void bfs(int x)
{
	int rear = 0, front = 0;
	q[rear++] = x;
	visit[x] = 1;
	while (front < rear)
	{
		int xp = q[front++];
		if (xp == G)//���� ��ҿ� ���� �ϸ� 
		{
			printf("%d", visit[xp]-1);
			return;
		}
		int dx[2] = { xp + U,xp - D };//��ġ���� u d �ۿ� ���� 
		for (int i = 0; i < 2; i++)
		{
			int xx = dx[i];
			if (1 <= xx && xx <= F)//�����ϼ� �ִ� ���� 1��~F�� 
			{
				if (visit[xx] == 0)
				{
					visit[xx] = visit[xp] + 1;
				
					q[rear++] = xx;
				}
			}
		}
	}
	printf("use the stairs");
	return;
}
int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	bfs(S);//��ȣ ��ġ���� ���� 
}