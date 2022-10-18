#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int M, N;
int primeN[10005];
int visit[10005];
void prime() //에라토스테네스의 체
{
	for (int i = 0; i <= 10005; i++)
	{
		primeN[i] = 1;
	}
	for (int i = 2; i * i <= 10000; i++)
	{
		for (int j = 2 *i; j <= 10000; j += i)
		{
			primeN[j] = 0;
		}		
	}	
}
void int_to_string(int a, char s[]) 
{ //a를 문자열로 변환해 s로 복사
	for (int i = 0; i < 4; i++) 
	{
		s[3 - i] = a % 10 + '0';
		a /= 10;
	}
	s[4] = '\0';
}


void bfs(int y, int x)
{
	//visit 초기화 
	for (int i = 0; i < 10005; i++)
	{
		visit[i] = 0;
	}
	//큐생성
	int q[100001];
	int q2[100001];
	int rear = 0, front = 0;
	int rear2 = 0, front2 = 0;

	//bfs 시작 
	q[rear++] = y;
	q2[rear2++] = 0;
	visit[y] = 1;

	while (front < rear)
	{
	
		int yp = q[front++];
		int cnt = q2[front2++];
		if (yp == x)
		{
			printf("%d\n", cnt);
			return;
		}
		char num[5];
		int_to_string(yp, num);
		
		for (int i = 0; i <= 3; i++) 
		{
			char digit = num[i];
			for (int j = 0; j <= 9; j++) 
			{
				if (j == 0 && i == 0)
				{
					continue; 
				}
				num[i] = j + '0';
				int tmp = atoi(num);
				if (visit[tmp]==0 && primeN[tmp]==1) 
				{ 
					q[rear++] = tmp;
					q2[rear2++] = cnt+1;
					visit[tmp] = 1;
				}
			}
			num[i] = digit;
		}
	}
	printf("Impossible\n");
	return;
}

int main()
{
	int T;
	prime();
	scanf("%d", &T);

	for (int i = 0; i < T; i++) 
	{
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		bfs(num1, num2);	
	}
}