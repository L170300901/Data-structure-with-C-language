#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char chess[8][8];
int cnt=0;
int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf(" %c", &chess[i][j]);
		}
	}
	//집어 넣기 끝 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0)
			{
				if (chess[i][j] == 'F')
				cnt++;
			}
			if (i % 2 == 1 && j % 2 == 1)
			{
				if(chess[i][j] == 'F')				
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;

}