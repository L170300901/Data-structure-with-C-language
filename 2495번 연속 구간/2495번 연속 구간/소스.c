#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char arr[10];
int num[3];
int main()
{
	int i = 0;
	for (int j = 0; j < 3; j++)
	{
		int cnt = 0, a = 0, cnt2 = 0;
		char temp = NULL;
		int max = 0;


		gets(arr);// 문자열 받기
		for (int i =0; i < 8; i++)
		{
			if (arr[i] == arr[i+1])
			{
				cnt++;
			}
			else
			{
				if (max < cnt) 
				{
					max = cnt;
				}
				cnt = 0;
			}
		}
		num[i] = max;
		i++;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", num[i]+1);
	}
	return 0;
}
