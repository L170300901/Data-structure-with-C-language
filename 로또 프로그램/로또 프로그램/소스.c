#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int num[6];
int main()
{
	int lot;
	
	int cnt = 0;
	while (cnt < 6)
	{
		int temp = 1;
		
		scanf("%d", &lot);
		for (int i = 0; i <= cnt; i++)
		{
			if (num[i] == lot)
			{
				printf("같습니다\n");
				temp = 0;
				break;
			}
		}
		if (temp == 1)
		{
			num[cnt] = lot;
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}
