#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main(void)
{
	char a[4], b[4];
	int count;
	scanf(" %s", a);
	scanf("%d", &count);
	int i,j,k;
	int S = 0, B = 0,flag=0;
	for (i = 0; i < count; i++)
	{
		scanf(" %s", b);
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (a[j] == b[k])
				{
					if (j == k)
					{
						S++;	
					}
					
					if(j!=k)
					{
						B++;
					}			    
				}						
			}
		}
		if (S == 3)
		{
			printf("3S\n");
			printf("SUCCESS");
			return 0;
		}
		else if (S == 0 && B == 0)
		{
			printf("out\n");
		}
		else
		{
			printf("%dS%dB\n", S, B);
			S = 0;
			B = 0;
		}
	
	}
	printf("FAIL");
	return 0;
}