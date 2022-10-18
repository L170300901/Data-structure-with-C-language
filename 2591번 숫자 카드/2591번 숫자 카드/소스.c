#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int arr[45];
int dp[45];
int cnt = 1;
char t;
int main()
{
	while (1)
	{
		if (scanf("%c",&t)==-1)
		{
			break;
		}
		if ('0' <= t && t <= '9')
		{
			arr[cnt++] = t - 48;
		}
		else
		{
			break;
		}
	}
	dp[0] = 1;
	dp[1] = 1;
	cnt--;
	for (int i = 2; i <= cnt; i++)
	{
		if (arr[i - 1] == 0 && arr[i] == 0)
		{
			dp[cnt] = 0;
			break;
		}
		else if (arr[i] == 0 && 4<= arr[i-1])
		{
			dp[cnt] = 0;
			break;
		}
		else if (arr[i - 1] == 0)
		{
			dp[i] = dp[i-1];
		}
		else if (arr[i] != 0)
		{
			if (arr[i - 1] * 10 + arr[i] <= 34)
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}
		else
		{
			dp[i] = dp[i - 2];
		}
	}
	if (cnt == 0)
	{
		printf("0");

	}
	else if (cnt == 1 && arr[1] == '0')
	{
		printf("0");
	}
	else
	{
		printf("%d", dp[cnt]);
	}
}