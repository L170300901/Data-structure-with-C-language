#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int num[100];
int cnt;
void fuction(int num)
{
	if (num > 0)
	{
		fuction(num / 2);
		printf("%d", num % 2);
		//num[cnt] = num % 2;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	fuction(n);

}