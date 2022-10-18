#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char chess[55][55];
char white[9][9] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
char black[9][9] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};
int main()
{
	int N, M,cnt,cnt2,temp=187654321,temp2;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %c", &chess[i][j]);
		}		
	}
	//집어 넣기 끝
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			cnt = 0;
			cnt2 = 0;
			for (int a = i; a < i + 8; a++)
			{
				for (int b = j; b < j + 8; b++)
				{
					if (white[a - i][b - j] != chess[a][b])
					{
						cnt++;
					}
					if (black[a - i][b - j] != chess[a][b])
					{
						cnt2++;
					}
				}
			}
			if (cnt > cnt2)
				temp2 = cnt2;
			else
				temp2 = cnt;

			if (temp > temp2)
				temp = temp2;

		}
	}
	printf("%d", temp);

    return 0;
}