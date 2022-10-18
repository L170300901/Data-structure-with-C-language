#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	int n,m;
	int count;
	scanf("%d %d", &n,&count);
	int n1 = 0, n2 = 0, n3 = 0;
	int m1 = 0, m2 = 0,m3 = 0;
	n1 = n / 100;
	n2 = (n%100) / 10;
	n3 = (n % 100) % 10;
	int i;
	int s = 0;
	int b = 0;
	for (i = 0; i < count; i++)
	{
		
		scanf("%d", &m);
		m1 = m / 100;
		m2 = (m % 100) / 10;
		m3 = (m % 100) % 10;
		if (n1 == m1 || n2 == m2 || m3 == n3)
		{
			s = 1;
		}
		else if (n1 == m1 || n2 == m2 && n1 == m1 || n3 == m3&& n2 == m2 || n3 == m3)
		{
			s = 2;
		}
		else if (n1 == m1 && n2 == m2 && m3 == n3)
		{
			s = 3;
		}

		if (n1 == m2 || n1 == m3 || n2 == m3||n2==m1||n3==m1||m3==m2)
		{
			b = 1;
		}
		else if (n1 == m2 || n1 == m3 && n2 == m3)
		{
			b = 2;
		}
		else if (n1 == m2 || n1 == m3 && n2 == m1 || n2 == m3  && n3 == m1 || n3 == m2)
		{
			b = 3;
		}
		printf("%d S ", s);
		printf("%d B ", b);
	}
	
	return 0;


}