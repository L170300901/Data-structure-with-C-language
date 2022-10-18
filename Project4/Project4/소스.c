#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdio.h>

int main()
{
	char ch[200];
	scanf("%s", &ch);
	if ((ch >= 'A') && (ch <= 'Z'))
	{
		ch =ch+('a' - 'A');
		printf("%c", ch[200]);
	}
	return 0;
}
