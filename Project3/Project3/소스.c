#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int m = 0, c = 0, o = 0;
int main(void)
{
	
	scanf("%d%d%d", &m, &c, &o);
	if (0 <= m  && m <= 30)
	{
		printf("%d, Blue", m);
		
	}
	else if (31 <= m && m<= 80)
	{
		printf("%d, Green", m);
		
	}
	else if (81 <= m && m <= 150)
	{
		printf("%d, Yellow", m);
	}
	else if (151 <= m)
	{
		printf("%d, Red", m);
	}
	printf("\n");
	if (0 <=c && c<= 15)
	{
		printf("%d, Blue", c);
	}
	else if (16 <= c && c <= 35)
	{
		printf("%d, Green", c);
	}
	else if (36 <= c && c <= 75)
	{
		printf("%d, Yellow", c);
	}
	else if (76 <= c)
	{
		printf("%d, Red", c);
	}

	printf("\n");
	if (0 <= o && o <= 30)
	{
		printf("%d, Blue", o);
	}
	else if (31 <= o && o <= 90)
	{
		printf("%d, Green", o);
	}
	else if (91 <= o && o <= 150)
	{
		printf("%d, Yellow", o);
	}
	else if (151 <= o)
	{
		printf("%d, Red", o);
	}
	printf("\n");
	int middle = 0;
	middle = (m + c) / 2;
	if (middle >= 115)
	{
		printf("Stop");
		printf("\n");
		printf("SMS");
	}
	else if (middle >= 58 && middle <= 115)
		printf("Yellow");


	return 0;
}