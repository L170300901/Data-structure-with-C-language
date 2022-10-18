#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int num;
	scanf("%d", &num);
	int cnt = 0;
	while (1)
	{

		if (num % 5 == 0)
		{
			num= num / 5;
			cnt++;
			//printf("$$");
			//printf("%d\n",cnt);
			
		}
		if (num == 1)
		{
			printf("%d\n", cnt);
			return 0;
		}
	
		else 
		{
			if (num % 2 == 0)
			{
				//printf("$$"); 
				num = num / 2;
				cnt++;
				
			}
			else
			{
				num = num - 1;
				cnt++;
				
			}
		}
	}
	return 0;
}