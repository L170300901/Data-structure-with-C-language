#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[6][6];
int visit[6][6];
int answer;
int chk;
void check()
{
	int cntt = 0;
	//가로 검사
	for (int i = 0; i < 5; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 5; j++)
		{
			if (visit[i][j] == 1)
			{
				cnt++;
			}
		}
		if (cnt == 5)
		{
			cntt++;
		}
	}
	//세로검사
	for (int j = 0; j < 5; j++)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			if (visit[i][j] == 1)
			{
				cnt++;
			}
		}
		if (cnt == 5)
		{
			cntt++;
		}
	}
	//대각선 검사
	if (visit[0][0] == 1 && visit[1][1] == 1 && visit[2][2] == 1 && visit[3][3] == 1 && visit[4][4] == 1)
	{
		cntt++;
	}
	if (visit[0][4] == 1 && visit[1][3] == 1 && visit[2][2] == 1 && visit[3][1] == 1 && visit[4][0] == 1)
	{
		cntt++;
	}
	if (cntt >= 3)
	{
		printf("%d", answer);
		chk = 1;
		return;
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d ", &arr[i][j]);
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int num;
			scanf("%d ",&num);
			answer++;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (num == arr[i][j])
					{
						visit[i][j] = 1;
					}
				}
			}
			check();
			if (chk == 1)
			{
				return 0;
			}
			
		}

	}
}