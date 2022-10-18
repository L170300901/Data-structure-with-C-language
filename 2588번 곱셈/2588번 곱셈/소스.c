#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	int num, num2;
	int a, a2, a3;
	scanf("%d %d", &num, &num2);
	a = num2 / 100;
	a2 = (num2 % 100) / 10;
	a3= (num2 % 100) % 10;
	printf("%d\n", num * a3);
	printf("%d\n", num * a2);
	printf("%d\n", num * a);
	printf("%d\n", num * num2);
	return 0;

}