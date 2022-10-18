#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
char word[100];
int main()
{
	int len;
	int cnt = 0;
	gets(word);//문장 입력 
	len = strlen(word);
	for (int i = 0; i < len; i++)
	{
		if ((word[i] >= 'A') && (word[i] < 'Z'))
		{
			word[i] += ('a'-'A');
			cnt++;
		}
	}
	puts(word);
	printf("%d\n", cnt);

}