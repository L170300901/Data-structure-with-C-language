#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int n[10];
	for (int i = 1; i <=6; i++)
	{
		scanf("%d", &n[i]);
	}
	int cnt = 0;
	cnt =cnt+ n[6];
	n[6] = 0;
	cnt =cnt+ n[5];
	
	for (int i = 0; i < n[5]; i++)
	{
	
			n[1] = n[1] - 11;
			
	}
	if (n[1] < 0)
	{
		n[1] = 0;
	}
	n[5] = 0;
	cnt = cnt+n[4];
	for (int i = 0; i < n[4]; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (n[2] > 0)
			{
				n[2]--;
			}
			else 
			{
				n[1] =n[1]- 4;
			}
		}
	}
	n[4] = 0;
	cnt =cnt+ (n[3] / 4);	
	int k= n[3] % 4;
	if (k > 0)
	{		
		cnt++;
		if (k == 1)
		{
			if (n[2] > 4)
			{
				n[2] = n[2] - 5;
				n[1] = n[1] - 7;
			}
			else if (n[2] == 4)
			{
				n[2] = n[2] - 4;
				n[1] = n[1] - 11;
			}
			else if (n[2] == 3)
			{
				n[2] = n[2] - 3;
				n[1] = n[1] - 15;
			}
			else if (n[2] == 2)
			{
				n[2] = n[2] - 2;
				n[1] = n[1] - 19;
			}
			else if (n[2] == 1)
			{
				n[2] = n[2] - 1;
				n[1] = n[1] - 23;
			}
			else if (n[2] == 0)
			{
				n[1] = n[1] - 27;
			}		
		}
		else if (k == 2)
		{			
			if (n[2] > 3)
			{
				n[2] = n[2] - 3;
				n[1] = n[1] - 6;
			}
			else if (n[2]== 3)
			{
				n[2] = n[2] - 3;
				n[1] = n[1] - 6;
			}
			else if (n[2] == 2)
			{
				n[2] = n[2] - 2;
				n[1] = n[1] - 10;
			}
			else if (n[2]== 1)
			{
				n[2] = n[2] - 1;
				n[1] = n[1] - 14;
			}
			else if (n[2] == 0)
			{
				n[1] = n[1] - 18;
			}
		}
		else if (k == 3)
		{
			if (n[2] > 1)
			{
				n[2] = n[2] - 1;
				n[1] = n[1] - 5;
			}
			else if (n[2] == 1)
			{
				n[2] = n[2] - 1;
				n[1] = n[1] - 5;
			}
			else if (n[2] == 0)
			{
				n[1] = n[1] - 9;
			}
		}
	}
	if (n[1] < 0)
	{
		n[1] = 0;
	}
	if (n[2] < 0)
	{
		n[2] = 0;
	}
	cnt =cnt+ (n[2] / 9);	
	if (n[2] % 9 > 0)
	{
		cnt++; 
		n[1] =n[1]- (9 - n[2] % 9) * 4;
	}
	if (n[1] < 0)
	{
		n[1] = 0;
	}
	cnt =cnt+ (n[1] / 36);
	if (n[1] % 36 > 0)
	{
		cnt++;
	}
	printf("%d", cnt);
	return 0;	
}