#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _arr
{
	int front;
	int back;
	
}Arr;
Arr arr[100005];
int in[32005];
int q[1000000];
int cnt;
int rear = 0, front = 0;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[cnt].front = a;
		arr[cnt].back = b;
		cnt++;
		in[b]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (in[i] == 0)
		{
			q[rear++] = i;
		}
	}
	while (front < rear)
	{
		int here = q[front++];
		printf("%d ", here);		
		for (int i=0;i<cnt;i++)
		{
			if (arr[i].front==here)
			{
				in[arr[i].back]--;
				if (in[arr[i].back] == 0)
				{
					q[rear++] = arr[i].back;
				}

			}	
		}
	}
	return 0;
}