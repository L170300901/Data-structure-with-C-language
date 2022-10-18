#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char name[25];//오민석 이름 
int num,temp;
char girl[25];//여자 이름 넣을꺼 
char answer[25];//답 넣을꺼 
int l, o, v, e, max;
int cnt1, cnt2, cnt3, cnt4;
int main()
{
	scanf(" %s", name);//오민석 이름 입력 받음 
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] == 'L')
		{
			l;
		}
		else if (name[i] == 'O')
		{
			o++;
		}
		else if (name[i] == 'V')
		{
			v++;
		}
		else if (name[i] == 'E')
		{
			e++;
		}
	}
	//오민석 이름 끝 
	printf("%d\n", l);
	printf("%d\n", o);
	printf("%d\n", v);
	printf("%d\n", e);
	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf(" %s", girl);
		for (int j = 0; j < strlen(girl); j++)
		{
			if (girl[j] == 'L')
			{
				cnt1++;
			}
			else if (girl[j] == 'O')
			{
				cnt2++;
			}
			else if (girl[j] == 'V')
			{
				cnt3++;
			}
			else if (girl[j] == 'E')
			{
				cnt4++;
			}
		}
		cnt1 = cnt1 + l;
		cnt2 = cnt2 + o;
		cnt3 = cnt3 + v;
		cnt4 = cnt4 + e;
		temp = ((cnt1 + cnt2) * (cnt1 + cnt3) * (cnt1 + cnt4) * (cnt2 + cnt3) * (cnt2 + cnt4) * (cnt3 + cnt4)) % 100;
		if (max < temp)
		{
			max = temp;
			strcpy(answer, girl);
		}
		cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0,temp=0;
	}
	if (max == 0)
	{
	}
	printf("%s", answer);
	return 0;
}