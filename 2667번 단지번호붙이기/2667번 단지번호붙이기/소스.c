#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


/*
int n;
char map[30][30];//문자형 
int answer[30];
int visit[30][30];//정수형 
int cnt;
int num;
void dfs(int i, int j);
void back(int i, int j);

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &map[i]);	
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == '1'&&visit[i][j]!=1)//시작점 
			{
				num++;
				dfs(i, j);

			}
		}
	}
	for (int i = 1; i <= num;i++)
	{
		printf("%d", answer[i]);
	}


}
void dfs(int i, int j)
{
	cnt++;
	visit[i][j] = 1;//방문시 숫자1 표시 
	for (int a = i; a <= n; i++)
	{
		if (map[a][j] == '0')
		{
			int k;//세로로 내려갈꺼임 행 저장할꺼 
			k = j;
			if (map[a][k + 1] == '1')
			{
				dfs(a, k + 1);
			}
			else//돌아 가야댐 
			{
				back(a - 1, k + 1);

			}

		}
		else
		{
			for (int b = j; b <= n; j++)
			{
				if (map[a][b] == '1' && visit[a][b] != 1)
				{
					//map에서 문자 1이고 vist에서 숫자 1이 아닐때
					dfs(a, b);
				}
			}

		}

	}
}
void back(int i, int j)
{
	if (map[i + 1][j] == '1')
	{
		dfs(i + 1, i);
	}
	else
	{
		if (i - 1 == 0)//이어진게 없을떄
		{
			answer[num] = cnt;

		}
		back(i - 1, j);
	}

}


*/