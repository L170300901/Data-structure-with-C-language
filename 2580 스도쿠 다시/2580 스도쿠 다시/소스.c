#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int arr[9][9];
int num[10];
int chk;
typedef struct _q
{
	int y;//yÁÂÇ¥
	int x;// x ÁÂÇ¥
}queue;
queue V[2000000];
int rear = 0, front = 0;
int rear2 = 0;
int result;
int chk;
void answer()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void check(int y,int x, int num)
{
	result = 0;
	for (int i = 0; i < 9; i++)
	{
		if (arr[y][i] == num)
		{
			//printf("###############1111111111\n");
			//printf("y====%d i==%d num===%d\n", y,i, num);
			result= 2;
			return;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][x] == num)
		{
			//printf("##############22222222222222\n");
			//printf("i====%d x====%d num===%d\n", i, x, num);
			result= 2;
			return;
		}
	}
	int yy = (y / 3) * 3;
	int xx = (x / 3) * 3;
	//printf("yy=====%d xx====%d\n", yy, xx);
	for (int i = yy; i < 3 + yy; i++)
	{
		for (int j = xx; j < 3 + xx; j++)
		{
			if (arr[i][j] == num)
			{
				//printf("##############3333333333333\n");
				result = 2;
			}
		}
	}
}
void dfs(int cnt)
{

	printf("cnt ==== %d rear2===%d\n", cnt,rear2);

	if (cnt == rear2)
	{
		//printf("####\n");
		chk = 1;
		return;
	}
	queue q[1001];
	for (int i = 0; i < rear2; i++)
	{
		q[i].x = V[i].x;
		q[i].y = V[i].y;
	}
	rear = rear2;
	front = cnt;
	while (front < rear)
	{
		int yp = q[front].y;
		int xp = q[front].x;
		front++;
		
		for (int i =1;  i<= 9; i++)
		{
			//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			printf("yp===%d xp====%d  i===%d \n", yp, xp,i);
			check(yp, xp, i);
			printf("result===%d\n", result);
			if (result== 0)
			{
				arr[yp][xp] = i;
				answer();
				//printf("cnt===%d\n", cnt);
				dfs(cnt+1);
				if (chk == 1)
				{
					return;
				}
				arr[yp][xp] = 0;
				//front = 0;
			}
		}
	}

}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				V[rear2].y = i;
				V[rear2].x = j;
				rear2++;
			}
		}
	}
	dfs(0);
	printf("####\n");
	answer();
	return 0;

}