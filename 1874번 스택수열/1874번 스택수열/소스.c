#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int stack[100005];
char answer[200005];
int top=0;
int temp = 0;
int cnt;
int chk;
void push()
{
	temp++;
	answer[cnt++] = '+';
	stack[++top] = temp;
}
void pop()
{
	if (top <= 0)
	{
		printf("NO\n");
		chk = 1;
		return;
		//top = 0;
	}
	else
	{
		answer[cnt++] = '-';
		top--;
	}
}
int main()
{
	int n,num;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		while(1)
		{
			//printf("top===%d temp===%d \n", top,temp);
			if (stack[top] == num)
			{
				pop();
				if (chk == 1)
				{
					return 0;
				}
				break;
			}
			if (stack[top] < num)
			{
				push();
				//printf("%d\n", stack[top]);
				if (stack[top] >num)
				{
					printf("NO\n");
					return 0;
				}
			}
			else if (stack[top] > num)
			{
				pop();
			}
			
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%c\n", answer[i]);
	}
}