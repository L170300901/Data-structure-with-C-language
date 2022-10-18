#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num[1000005];
int stack[100005];
int cnt;
int main()
{
	int N;
	int top = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);

	}
	for (int i = 0; i <N;i++)
	{
		top++;
		stack[top] = num[N - i - 1];
	}
	//거꾸러 집어넘 
	/*for (int i = 0; i < N; i++)
	{
		printf("%d", stack[i]);
	}*/
	//잘 거꾸로 뒤집어 졌는지 확인 
	
	while(top!=-1)
	{
		
		/*for (int i = 0; i <= top; i++)
		{
			printf("%d", stack[i]);
		}
		printf("  #top=%d\n", top);*/
	    if (top == 0)
		{
			//printf("top==0일때에\n");

			printf("-1");
			top--;
		}
		else if (stack[top] < stack[top - 1])
		{
			//printf("두번째꺼\n");
			printf("%d ", stack[top - 1]);
			top--;
		}	
		else
		{
			//printf("넘버3\n");
			int i = 1;
			while (i != top)
			{
				if (stack[top] < stack[top - i])
				{
					//printf("##\n");
					printf("%d ", stack[top - i]);
					top--;
					cnt++;
					break;
				}
				i++;
			}
			if (i == top&&cnt==0)
			{
				//printf("##2\n");
				if (stack[top] < stack[top - i])
				{
					printf("%d ", stack[top - i]);
					top--;
				}
				else
				{
					printf("-1 ");
					top--;
				}
			
			}
			cnt = 0;

			
		}
	}
	return 0;
}