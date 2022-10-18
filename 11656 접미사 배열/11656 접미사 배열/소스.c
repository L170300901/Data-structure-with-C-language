#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char A[20];
char B[10];
char C[20];
char D[10];
char plus[30];

int main()
{
	int gap;
	scanf(" %s %s %s %s", A, B, C, D);
	strcat(A, B);
	strcat(C, D);
	int len=strlen(A);
	if (strlen(A) < strlen(C))
	{
		len = strlen(C);

	}
	if (strlen(A) != strlen(C))
	{
		if (strlen(A) < strlen(C))
		{
			gap = strlen(C) - strlen(A);
			for (int  i = strlen(A);i>=0; i--)
			{
				A[i + gap]=A[i];
			}
			for (int j = 0; j < gap; j++)
			{
				A[gap - 1] = 0;
			}
		}
		else
		{
			gap = strlen(A) - strlen(C);
			for (int i = 0; i < strlen(C); i++)
			{
				C[i + gap] = C[i];
			}
			for (int j = 0; j < gap; j++)
			{
				C[gap - 1] = 0;
			}

		}
	}
	for (int i = len-1;i>=0; i--)
	{
		int temp;
		temp=(A[i]-'0') + (C[i]-'0');
		if (temp >= 10)
		{
			if (plus[i] == 0)
			{
				plus[i - 1] = ((plus[i - 1]) + 1) + '0';
				plus[i] = (temp - 10) + '0';
			}
			else
			{
				plus[i - 1] = ((plus[i - 1]) + 1) + '0';
				plus[i] = (plus[i]-'0')+(temp - 10) + '0';
			}
		}
		else
		{
			if (plus[i] == 0)
			{
				plus[i] = (plus[i]) + temp + '0';

			}
			else
			{
				plus[i] = (plus[i]-'0') + temp + '0';

			}			
		}
	}

	printf("%s", plus);

}
	