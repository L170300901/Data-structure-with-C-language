#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int num[10];
	int num2[10];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			
			if (num[i] >= num[j])
			{
				int temp;
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}

		}
	}
	//printf("%d\n", sum); 
	int limit = 100;
	int sum2 = sum - limit;
	//printf("%d", sum2); 40�� ����� ��� �ϸ� �� 
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			
			if (num[i] + num[j] == sum2)
			{
				num2[0] = i;
				num2[1] = j;
				//�ֳ� äũ �ؼ� �ֳ� ���� ��� 
			}

		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (i != num2[0] && i != num2[1])
		{
			printf("%d\n", num[i]);
		}
	}
	return 0;
}