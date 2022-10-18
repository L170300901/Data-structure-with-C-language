#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char str1[205];
char str2[105];
char str3[105];
int main()
{
	int num;
	scanf("%d", &num);
	int i, j, k, l,temp;
	int cnt = 0;
	int len1;
	for (i = 0; i < num; i++)
	{
		scanf("%s", str1);
		int check1 = 0, check2 = 0, check3 = 0;
		
		len1 = strlen(str1);
		
		for (j = 0; j < len1; j++)
		{
			if (str1[j] == '@') {
				temp = j; 
				break;
			}	
		}
		//로컬파트
		check1 = 1;
		for (k = 0; k < temp; k++)
		{
			if ((str1[k] >= 'a' && str1[k] <= 'z;') || (str1[k] >= 'A' && str1[k] <= 'Z') || (str1[k] >= '0' && str1[k] <= '9') || (str1[k] == '-') || (str1[k] == '.'))
			{

			}
			else
			{
				check1 = 0;
				break;
			}
		}
		//도메인파트
		check2 = 1, check3 = 1;
		for (k = temp + 1; k < len1; k++)
		{
			if (str1[k] == '@')
			{
				check3 = 0;
				break;
			}
			if ((str1[k] >= 'a' && str1[k] <= 'z;') || (str1[k] >= 'A' && str1[k] <= 'Z') || (str1[k] >= '0' && str1[k] <= '9') || (str1[k] == '-') || (str1[k] == '.'))
			{

			}
			else
			{
				check2 = 0;
				break;
			}
		}

		if (check1 == 1 && check2 == 1 && check3==1)
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
	
	return 0;
}