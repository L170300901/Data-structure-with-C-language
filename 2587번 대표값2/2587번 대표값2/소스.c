#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int num[6];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5; j++)
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
	printf("%d\n", sum / 5);
	//평균 출력 완료
	printf("%d\n", num[2]);
	return 0;
	
}