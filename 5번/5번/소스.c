#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	char str[500];
	int n, i,j;
	int cnt = 0;
	int flag = 0;
	scanf("%d", &n);
	int cmt = 0;
	int len = 0;

	for (i = 0; i < n; i++)
	{
		scanf(" %s", str);
		len = strlen(str);
		flag = 0;
		for (j = 0; j < len; j++) 
		{ 
			if (str[j] != str[len - j - 1])
				flag = 1;
		}
		if (flag == 1)
		{
			cnt++;
		}
		else if (flag == 0)
		{
			if (cmt < len)
			{
				cmt = len;
			}
		}
			
	}
	if (cnt == n)
	{
		printf("-1");
	}
	else
	{
		printf("%d",cmt);
	}
	return 0;
	
}