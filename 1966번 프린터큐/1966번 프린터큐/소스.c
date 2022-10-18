#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef struct _queue
{
	int n;
	int zhong;
}Queue;
int main()
{
	int num, N, M;
	scanf("%d", &num);
	while (num--)
	{
		scanf("%d %d", &N, &M);
		int front = 0, rear = 0;
		Queue q[10005];
		Queue answer[105];
		for (int i = 0; i < N; i++)
		{
			int temp;
			scanf("%d", &temp);
			q[rear].n = i;
			q[rear].zhong = temp;
			rear++;
		}
		int cnt = 0;
		while (rear>front)
		{
			int chk = 0;
			int a = q[front].n;
			int b = q[front].zhong;
			front++;
			//printf("rear====%d", rear);
			for (int i = front; i < N; i++)
			{
				if (q[i].zhong > b)
				{
					q[rear].n = a;
					q[rear].zhong = b;
					rear++;
					chk = 1;
					N++;
					break;	
				}		
			}
			if (chk == 0)
			{
				answer[cnt].n = a;
				answer[cnt].zhong = b;
				cnt++;
			}
			/*printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
			for (int i = rear; i < front; i++)
			{
				printf("----------------%d\n",i);
				printf("%d\n", q[i].n);
				printf("%d\n", q[i].zhong);

			}
			*/
		}
		for (int i = 0; i < N; i++)
		{
			if (M == answer[i].n)
			{
				printf("%d\n", i+1);
				break;
			}
		}	
	}
}