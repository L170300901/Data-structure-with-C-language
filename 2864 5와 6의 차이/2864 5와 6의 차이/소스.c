#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char num[7];
char num2[7];
int numm[7], numm2[7];
int min, max;
int main()
{
	scanf(" %s %s", &num, &num2);
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] == '5')
		{
			num[i] = '6';
		}
	}
	for (int i = 0; i < strlen(num2); i++)
	{
		if (num2[i] == '5')
		{
			num2[i] = '6';
		}
	}
	//�ִ� ���� ���ϱ� ���� ���� 5�� ���� 6���� �ٲ� 
	
	max = atoi(num) + atoi(num2);
	for (int i = 0; i < strlen(num); i++)
	{
		if (num[i] == '6')
		{
			num[i] = '5';
		}
	}
	for (int i = 0; i < strlen(num2); i++)
	{
		if (num2[i] == '6')
		{
			num2[i] = '5';
		}
	}
	min = atoi(num) + atoi(num2);
	printf("%d %d\n", min, max);
}