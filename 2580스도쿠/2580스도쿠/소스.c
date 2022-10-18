#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int arr[9][9];
int num[10];
int chk;
typedef struct _q
{
	int a;//y좌표
	int b;// x 좌표
}queue;
queue q[2000000];
int rear = 0, front = 0;
void stoku();
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
void init()
{
	for (int i = 0; i <= 9; i++)
	{
		num[i] = 0;
	}
}
void check1(int a,int b)
{
	//가로 검사
	for (int i = 0; i < 9; i++)
	{
		num[arr[a][i]]++;
	}
	if (num[0] >= 2)
	{
		return;
	}
	else
	{
		for (int ii = 1; ii <= 9; ii++)
		{
			if (num[ii] == 0)
			{
				arr[a][b] = ii;
				chk = 1;
			}
		}
	}
}
void check2(int a, int b)
{
	for (int i = 0; i < 9; i++)
	{
		num[arr[i][b]]++;
	}
	if (num[0] >= 2)
	{
		return;
	}
	else
	{
		for (int ii = 1; ii <= 9; ii++)
		{
			if (num[ii] == 0)
			{
				arr[a][b] = ii;
				chk = 1;
			}
		}
	}
}
void check3(int a, int b)
{
	//3칸씩 검사
	if (0 <= a&&a < 3 && 0 <= b&&b < 3)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (0 <= a&&a < 3 && 3 <= b&&b < 6)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (0 <= a&&a < 3 && 6 <= b&&b < 9)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (3 <= a&&a < 6 && 0 <= b&&b < 3)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (3 <= a&&a < 6 && 3 <= b&&b < 6)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (3 <= a&&a < 6 && 6 <= b&&b < 9)
	{
		for (int i = 3; i < 6; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (6 <= a&&a < 9 && 0 <= b&&b < 3)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (6 <= a&&a < 9 && 3 <= b&&b < 6)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 3; j < 6; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
	if (6 <= a&&a < 9 && 6 <= b&&b < 9)
	{
		for (int i = 6; i < 9; i++)
		{
			for (int j = 6; j < 9; j++)
			{
				num[arr[i][j]]++;
			}
		}
		if (num[0] >= 2)
		{
			return;
		}
		else
		{
			for (int ii = 1; ii <= 9; ii++)
			{
				if (num[ii] == 0)
				{
					arr[a][b] = ii;
					chk = 1;
				}
			}
		}
	}
}
void dfs(int yp, int xp)
{
	for (int i = 1; i <=9; i++)
	{
		arr[yp][xp] = i;
		stoku();
	}

}
void stoku()
{
	while (front < rear)
	{
		chk = 0;
		int yp = q[front].a;
		int xp = q[front].b;
		front++;
		printf("yp==%d,xp==%d\n", yp, xp);
		init();
		check1(yp, xp);
		if (chk == 0)
		{
			init();
			check2(yp, xp);
			if (chk == 0)
			{
				init();
				check3(yp, xp);
				if (chk == 0)//체크 2개 했는데 못찾으면?? 다시 큐에 집어 넣을꺼임 
				{
					dfs(yp,xp);
					//q[rear].a = yp;
					//q[rear].b = xp;
					//rear++;
				}
			}
		}
		printf("@@@@@@\n");
		answer();
	}

}
int main()
{
	//일단 스토쿠 입력 받음 
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{
				q[rear].a = i;
				q[rear].b = j;
				rear++;
			}
		}
	}
	stoku();
	printf("@@@@@@\n");
	answer();
	return 0;
	
}