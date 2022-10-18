#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char num[10];//문자열 입력 받을 배열 
int num2[10];//숫자 0~9
int num3[10];//숫자 0~9개수 셀꺼 
int main()
{
	int cnt = 0;//6,9의 개수 셀꺼
	int cnt2 = 0;//문자 -> 숫자 바꾸고 집어 넣 
	scanf(" %s", num);
	if (strcmp(num, "0")==0)
	{
		printf("1");
		return 0;

	}
	for (int i = 0; i < strlen(num); i++)
	{
		num2[i] = num[i] - '0';
	}
	for (int j = 0; j < strlen(num); j++)
	{
		if (num2[j] == 0)
			num3[0]++;
		else if (num2[j] == 1)
			num3[1]++;
		else if (num2[j] == 2)
			num3[2]++;
		else if (num2[j] == 3)
			num3[3]++;
		else if (num2[j] == 4)
			num3[4]++;
		else if (num2[j] == 5)
			num3[5]++;
		else if (num2[j] == 6)
			num3[6]++;
		else if (num2[j] == 7)
			num3[7]++;
		else if (num2[j] == 8)
			num3[8]++;
		else if (num2[j] == 9)
			num3[6]++;

		
	}


	if (num3[6] % 2 == 0)
	{
		num3[6] = num3[6] / 2;
	}
	else
	{
		num3[6] = num3[6] / 2 + 1;
	}
	int ans = num3[0];

	for (int l = 0;l < 9; l++)
	{
		if (ans < num3[l])
			ans = num3[l];
	}
	printf("%d", ans);
	return 0;
}